#include "hashing.h"
#include "menu.h"
#include "cls.h"

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
    char plaintextHash[MAX_LEN];
    char ciphertextHash[MAX_LEN];
    char decryptedText[MAX_LEN];
    int randomValues[MAX_LEN];
    int choice;
    int randomValuesEncrypted = 0; // Flag to check if random values are stored

    do {
        printf("[1] Encrypt Custom Hashing\n");
        printf("[2] Decrypt Custom Hashing\n");
        printf("[3] Menu Utama\n");
        printf("Pilih menu (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	clear();
                printf("Masukkan pesan/plaintext: ");
                getchar();
                fgets(plaintextHash, sizeof(plaintextHash), stdin);
                customEncrypt(plaintextHash, ciphertextHash, randomValues);
                printf("Encrypted text: %s\n", ciphertextHash);
                randomValuesEncrypted = 1;
                
                printf("Tekan ENTER untuk continue...");
                getchar();
           		clear();
                break;
            case 2:
            	clear();
                if (!randomValuesEncrypted) {
                    printf("Error: Random values tidak ada. Coba untuk mengenkripsi sebuah text terlebih dahulu.\n");
                	break;
                } else {
                	printf("Ciphertext saat ini: %s", ciphertextHash);
                	customDecrypt(ciphertextHash, decryptedText, randomValues);
                	printf("Decrypted text: %s\n", decryptedText);
                	printf("Tekan ENTER untuk continue...\n");
                	getchar();
                	getchar();
                	clear();
                	break;
				}
            case 3:
                menu();
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n");
        }
    } while (choice != 3);

    return 0;
}

