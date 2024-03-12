#include "menu.h"

void menu()
{
    printf("\n==================== Menu ====================\n");
    printf("1. Encrypt Shifting + RSA \n");
    printf("2. Decrypt Shifting + RSA \n");
    printf("3. Keluar \n");
    printf("================================================\n");
}

void encryptMenu(int *pilihanEncryptMenu)
{
    do
    {
        printf("Encrypt yang akan digunakan :  1\n");
        /* Menampilkan menu */
        printf("1. Masukkan Teks\n");
        printf("2. Read File\n");
        printf("Pilih menu (1/2): ");
        scanf("%d", pilihanEncryptMenu); // Use the address-of operator here

        switch (*pilihanEncryptMenu)
        {
        case 1:
            break;
        case 2:
            printf("Membaca teks dari file untuk dienkripsi:\n");
            // Lakukan enkripsi teks dari file di sini
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih 1 atau 2.\n");
        }
    } while (*pilihanEncryptMenu != 1 && *pilihanEncryptMenu != 2);
}
