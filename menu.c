#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("\n\t\t\t\t\t\t==================== Menu ====================\n");
    printf("\t\t\t\t\t\t\t\t1. Encrypt \n");
    printf("\t\t\t\t\t\t\t\t2. Decrypt \n");
    printf("\t\t\t\t\t\t\t\t3. Keluar \n");
    printf("\t\t\t\t\t\t================================================\n");
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
                // Lakukan sesuatu untuk pilihan 1
                break;
            case 2:
                printf("Anda memilih Pilihan 2\n");
                // Lakukan sesuatu untuk pilihan 2
                break;
            case 3:
                printf("Anda memilih Pilihan 3\n");
                // Lakukan sesuatu untuk pilihan 3
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih 1-3.\n");
        }
    } while (pilihan != 3);

    return 0;
}
