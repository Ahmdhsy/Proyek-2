#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashing.h"
#include "shifting.h"
#include "cls.h"
#include "menu.h"

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
    	printf("Memory allocation failed\n");
    	exit(EXIT_FAILURE);
	}
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

struct Node* arrayToLinkedList(const char *array) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; array[i] != '\0'; ++i) {
        struct Node* newNode = createNode(array[i]);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    return head;
}

void linkedListToArray(struct Node* head, char *array) {
    struct Node* current = head;
    int i = 0;
    while (current != NULL) {
        array[i] = current->data;
        current = current->next;
        i++;
    }
    array[i] = '\0';
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("[%c]", current->data);
        current = current->next;
    }
    printf("\n");
}

void addRandomCharacter(struct Node* head, const char *replacementTable) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    char randomChar = rand() % strlen(replacementTable);
    struct Node* newNode = createNode(randomChar);
    current->next = newNode;
    newNode->prev = current;
}

void deleteRandomCharacter(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    if (current != NULL) {
        struct Node* prevNode = current->prev;
        if (prevNode != NULL) {
            prevNode->next = NULL;
            free(current);
        }
    }
}

char replaceSpace() {
	char symbol[] = {'/', '#', '$'};
	int numSymbol = sizeof(symbol) / sizeof(symbol[0]);
	int id = rand() % numSymbol;
	
	return symbol[id];
}

void customEncrypt(const char *plaintextHash, char *ciphertextHash, int *randomValues, const char *replacementTable) {
	char replace = replaceSpace();
    int len = strlen(plaintextHash);
    for (int i = 0; i < len; i++) {
        if (plaintextHash[i] != ' ') {
            int index = strchr(replacementTable, plaintextHash[i]) - replacementTable;
            randomValues[i] = rand() % strlen(replacementTable);
            ciphertextHash[i] = replacementTable[(index + randomValues[i]) % strlen(replacementTable)];
        } else {
            ciphertextHash[i] = replace;
        }
    }
    ciphertextHash[len] = '\0';
}

void customDecrypt(const char *ciphertextHash, char *plaintextHash, const int *randomValues, const char *replacementTable, const char *spaceSymbols, int numSymbols) {
    int len = strlen(ciphertextHash);
    for (int i = 0; i < len; i++) {
        int isSpaceSymbol = 0;
        for (int j = 0; j < numSymbols; j++) {
            if (ciphertextHash[i] == spaceSymbols[j]) {
                isSpaceSymbol = 1;
                break;
            }
        }
        if (!isSpaceSymbol) {
            int index = strchr(replacementTable, ciphertextHash[i]) - replacementTable;
            plaintextHash[i] = replacementTable[(index - randomValues[i] + strlen(replacementTable)) % strlen(replacementTable)];
        } else {
            plaintextHash[i] = ' ';
        }
    }
    plaintextHash[len] = '\0';
}

int menuHashing() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    int randomValues[MAX_LEN];
    struct Node* ciphertextLinkedList = NULL;
    char replacementTable[] = "!@%&{}|?`~*()-_+=;:<>QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";
    char spaceSymbol[] = {'/', '#', '$'};
    char *shiftedPlaintext = NULL, *decryptedPlaintext = NULL;
    int numSpaceSymbols = sizeof(spaceSymbol) / sizeof(spaceSymbol[0]);
    int choice, shift_value;
	char ch;
	
    srand(time(NULL));
	  
    do {
        printf("Menu Hashing:\n");
        printf("[1] Encrypt Hash\n");
        printf("[2] Decrypt Hash\n");
        printf("[3] Kembali ke Menu Utama\n");
		while (1) {
	        printf("Masukkan pilihanmu: ");
	        if (scanf("%d", &choice) == 1) {
	            while ((ch = getchar()) != '\n' && ch != EOF);
	            break;
	        } else {
	            printf("\033[1;31mError: Masukkan angka sesuai menu!\033[0m\n");
	            while ((ch = getchar()) != '\n' && ch != EOF);
	        }
		}	
		
        switch (choice) {
			case 1:
			    clear();
			    printf("Masukkkan plaintext: ");
			    getchar();
			    fgets(plaintext, sizeof(plaintext), stdin);
			    
			    size_t len;
			
			    len = strlen(plaintext);
			    if (len > 0 && plaintext[len - 1] == '\n') {
			        plaintext[len - 1] = '\0';
			        len--;
			    }
				
				clear();
				printf("Masukkan nilai pergeseran untuk shifting pesan: ");
            	scanf("%d", &shift_value);
				clear();
				
				printf("Plaintext (Sebelum Encrypting): %s\n", plaintext);
				
				shiftedPlaintext = shift_message(plaintext, shift_value);
				printf("Shifted plaintext: %s\n", shiftedPlaintext);
				
			    customEncrypt(shiftedPlaintext, ciphertext, randomValues, replacementTable);
			    printf("Ciphertext: %s\n", ciphertext);
				
			    ciphertextLinkedList = arrayToLinkedList(ciphertext);
			    printf("Linked list ciphertext: ");
			    printLinkedList(ciphertextLinkedList);
			
			    addRandomCharacter(ciphertextLinkedList, replacementTable);
			    printf("Linked list setelah menambahkan random character: ");
			    printLinkedList(ciphertextLinkedList);
			
			    system("pause");
			    clear();
			    break;
            case 2:
            	clear();
                if (ciphertextLinkedList == NULL) {
                    printf("\033[1;31mError: Tidak ada message untuk melakukan Decryption. Silakan Encryption terlebih dahulu!\033[0m\n");
                    system("pause");
                    clear();
                    break;
                }
                
                printf("Masukkan nilai pergeseran untuk unshifting pesan: ");
            	scanf("%d", &shift_value);
				clear();
				
                printf("Linked list saat ini dengan added character: ");
                printLinkedList(ciphertextLinkedList);
                deleteRandomCharacter(ciphertextLinkedList);
                
				printf("Linked list setelah hapus added character: ");
                printLinkedList(ciphertextLinkedList);	
                linkedListToArray(ciphertextLinkedList, ciphertext);
				
				printf("Ciphertext: %s\n", ciphertext);
                customDecrypt(ciphertext, plaintext, randomValues, replacementTable, spaceSymbol, numSpaceSymbols);
				
				decryptedPlaintext = shift_message(plaintext, -shift_value);
				printf("Shifted plaintext: %s\n", plaintext);
				
				printf("Plaintext (Setelah Decrypting): %s\n", decryptedPlaintext);
                
                system("pause");
                clear();
                break;
            case 3:
            	clear();
                freeLinkedList(ciphertextLinkedList);
                break;
            default:
            	printf("\033[1;31mError: Masukkan angka sesuai menu!\033[0m\n");
            	break;
        }
    } while (choice != 3);

    return 0;
}
