#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("\n\t\t\t\t\t\t==================== Menu ====================\n");
    printf("\t\t\t\t\t\t\t\t1. Encrypt \n");
    printf("\t\t\t\t\t\t\t\t2. Decrypt \n");
    printf("\t\t\t\t\t\t\t\t3. Keluar \n");
    printf("\t\t\t\t\t\t================================================\n");
}

void encrypt() {

}

void decrypt() {
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
                int pilihan;
                
                    do {
                    /* Menampilkan menu */
                    printf("1. Masukan Teks\n");
                    printf("2. Read File\n");
        
                    printf("Pilih menu (1/2): ");
                    scanf("%d", &pilihan);

                    switch (pilihan) {
                    case 1:
                
                    case 2:

                    } while (pilihan != 2);

                encrypt();
                break;
            case 2:
                printf("Anda memilih Pilihan 2\n");
                decrypt();
                break;
            case 3:
                printf("Anda memilih Pilihan 3\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih 1-3.\n");
        }
    } while (pilihan != 3);

    return 0;
}