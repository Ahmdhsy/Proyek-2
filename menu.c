#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("\n\t\t\t\t\t\t==================== Menu ====================\n");
    printf("\t\t\t\t\t\t\t\t1. Encrypt \n");
    printf("\t\t\t\t\t\t\t\t2. Decrypt \n");
    printf("\t\t\t\t\t\t\t\t3. Keluar \n");
    printf("\t\t\t\t\t\t==============================================\n");
}

void encrypt() {
    int pilihan;

    do {
    	printf("\n\t\t\t\t\t\t================== ENCRYPT ==================\n");
        printf("\t\t\t\t\t\t\tEncrypt yang akan digunakan :  1\n");
        /* Menampilkan menu */
        printf("\t\t\t\t\t\t\t1. Masukkan Teks\n");
        printf("\t\t\t\t\t\t\t2. Read File\n");
        printf("\t\t\t\t\t\t\tPilih menu (1/2): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("\t\t\t\t\t\t\tMasukkan teks yang akan dienkripsi:\n");
                // Lakukan enkripsi teks yang dimasukkan di sini
                break;
            case 2:
                printf("\t\t\t\t\t\t\tMembaca teks dari file untuk dienkripsi:\n");
                // Lakukan enkripsi teks dari file di sini
                break;
            default:
                printf("\t\t\t\t\t\t\tPilihan tidak valid. Silakan pilih 1 atau 2.\n");
        }
    } while (pilihan != 1 && pilihan != 2);
}

void decrypt() {
	printf("\n\t\t\t\t\t\t================== DECRYPT ==================\n");
    printf("\t\t\t\t\t\t\tAnda memilih Pilihan 2\n");
    // Implementasikan fungsi dekripsi di sini
}

int main() {
    int pilihan;

    do {
        menu();
        printf("\t\t\t\t\t\t\tMasukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Anda memilih Pilihan 1\n");
                encrypt();
                break;
            case 2:
                printf("Anda memilih Pilihan 2\n");
                decrypt();
                break;
            case 3:
                printf("\t\t\t\t\t\t\tAnda memilih Pilihan 3\n");
                break;
            default:
                printf("\t\t\t\t\t\t\tPilihan tidak valid. Silakan pilih 1-3.\n");
        }
    } while (pilihan != 3);

    return 0;
}
