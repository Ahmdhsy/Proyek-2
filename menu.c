#include "menu.h"
#include "cls.h"

void menu()
{
    printf("========================================\n");
    printf("                Main Menu               \n");
    printf("========================================\n");
    printf("1. Encrypt Shifting & RSA               \n");
    printf("2. Decrypt Shifting & RSA               \n");
    printf("3. Encrypt Shifting & Hashing           \n");
    printf("4. Encrypt Shifting & LSB               \n");
    printf("5. Decrypt Shifting & LSB               \n");
    printf("6. Exit                                 \n");
    printf("========================================\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void encryptMenu(int *pilihanEncryptMenu, char *metode) {
    int result;
    do {
        printf("Metode %s yang akan digunakan: 1\n", metode);
        printf("----------------------------------------\n");
        printf("[1] Masukkan Teks\n");
        printf("[2] Baca dari File\n");
        printf("----------------------------------------\n");
        printf("Pilih menu (1/2): ");
        result = scanf("%d", pilihanEncryptMenu);

        // Clear the input buffer to handle invalid input
        clearInputBuffer();

        if (result == 1) { // Check if scanf successfully read an integer
            switch (*pilihanEncryptMenu) {
                case 1:
                  
                    break;
                case 2:
                    
                    break;
                default:
                    printf("Pilihan tidak valid. Silakan pilih 1 atau 2.\n");
            }
        } else {
            printf("Input tidak valid. Masukkan angka 1 atau 2.\n");
        }
    } while (*pilihanEncryptMenu != 1 && *pilihanEncryptMenu != 2);
}
