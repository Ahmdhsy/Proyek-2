#include "menu.h"
#include "cls.h"

void menu()
{
	printf("\033[0;36m");
    printf("================= Menu =================\n");
    printf("1. Encrypt Shifting & RSA \n");
    printf("2. Decrypt Shifting & RSA \n");
    printf("3. Encrypt Shifting & Hashing\n");
    printf("4. Keluar \n");
    printf("========================================\n");
}

void encryptMenu(int *pilihanEncryptMenu, char *metode)
{
    do
    {
    	printf("\033[0;36m"); //mengubah warna teks
        printf("Metode %s yang akan digunakan :  1\n", metode);
        /* Menampilkan menu */
        printf("1. Masukkan Teks\n");
        printf("2. Read File\n");
        printf("Pilih menu (1/2): ");
        scanf("%d", pilihanEncryptMenu);
		clear();
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
