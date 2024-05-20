#include "hashing.h"
#include "menu.h"
#include "cls.h"

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

void addRandomCharacter(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    int randomValue = rand() % 26 + 'a';
    struct Node* newNode = createNode(randomValue);
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

void customEncrypt(const char *plaintextHash, char *ciphertextHash, int *randomValues) {
    int len = strlen(plaintextHash);
    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        randomValues[i] = rand() % 5 + 1;
        ciphertextHash[i] = plaintextHash[i] + randomValues[i];
    }
    ciphertextHash[len] = '\0';
}

void customDecrypt(const char *ciphertextHash, char *plaintextHash, const int *randomValues) {
    int len = strlen(ciphertextHash);
    for (int i = 0; i < len; ++i) {
        plaintextHash[i] = ciphertextHash[i] - randomValues[i];
    }
    plaintextHash[len] = '\0';
}

int menuHashing() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    int randomValues[MAX_LEN];
    struct Node* ciphertextLinkedList = NULL;
    int choice;

    srand(time(NULL)); // Seed the random number generator

    do {
        printf("\nMenu:\n");
        printf("[1] Encrypt Hash\n");
        printf("[2] Decrypt Hash\n");
        printf("[3] Kembali ke Menu Utama\n");
        printf("Masukkan pilihanmu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkkan plaintext: ");
                getchar(); // Consume newline
                fgets(plaintext, sizeof(plaintext), stdin); // Read entire line
                customEncrypt(plaintext, ciphertext, randomValues);
                printf("Ciphertext: %s\n", ciphertext);
                ciphertextLinkedList = arrayToLinkedList(ciphertext);
                printf("Linked list ciphertext: ");
                printLinkedList(ciphertextLinkedList);
                addRandomCharacter(ciphertextLinkedList);
                printf("Linked list setelah menambahkan random character: ");
                printLinkedList(ciphertextLinkedList);
                break;
            case 2:
                if (ciphertextLinkedList == NULL) {
                    printf("Error: tidak ada message untuk melakukan Decrypt. Encrypt terlebih dahulu.\n");
                    break;
                }
                printf("Linked list saat ini dengan added character: ");
                printLinkedList(ciphertextLinkedList);
                deleteRandomCharacter(ciphertextLinkedList);
                printf("Linked list setelah hapus added character: ");
                printLinkedList(ciphertextLinkedList);
                linkedListToArray(ciphertextLinkedList, ciphertext);
                printf("Ciphertext: %s\n", ciphertext);
                customDecrypt(ciphertext, plaintext, randomValues);
                printf("Decrypted text: %s", plaintext);
                break;
            case 3:
                freeLinkedList(ciphertextLinkedList);
                printf("Kembali ke menu tekan ENTER\n");
                getchar();
                clear();
                menu();
                break;
            default:
                printf("Pilihan salah. Masukkan input sesuai menu.\n");
        }
    } while (choice != 3);

    return 0;
}

