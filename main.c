#include "RSA.h"
#include "Shifting.h"
#include "menu.h"
#include "files.h"
#include "cls.h"
#include "hashing.h" // Tambahkan header file untuk fungsi hash

int main()
{
    /*Deklarasi Variabel*/
    int size, i, pilihan, pilihanEncryptMenu, shift_value;
    int *coded;
    char *message, *decoded, *inversed_shifted_message;
    char *shifted_message;

    /*Program*/
    pilihanEncryptMenu = 0;
    do
    {

        menu();
        printf(" Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
		clear();
        switch (pilihan)
        {
        case 1:
            encryptMenu(&pilihanEncryptMenu);
            generatePrimeNumber();
            public_key = generatePublicKey();
            private_key = generatePrivateKey(public_key);

            printf("This is public key: %d\n", public_key);
            printf("This is private key: %d\n", private_key);

            message = (char *)malloc(256 * sizeof(char));

            if (pilihanEncryptMenu == 1)
            {
                printf("Masukkan text yang ingin di enkripsi: ");
                getchar();
                fgets(message, 256, stdin);
                clear();

                if (strlen(message) > 0 && message[strlen(message) - 1] != '\n')
                {
                    while (getchar() != '\n')
                        ;
                }
            }
            else if (pilihanEncryptMenu == 2)
            {
                message = readFiles(message);
            }

            printf("Masukkan nilai pergeseran untuk shifting pesan: ");
            scanf("%d", &shift_value);
            getchar(); // Tangkap newline character yang tersisa setelah input
            clear();

            shifted_message = shift_message(message, shift_value);

            printf("Initial message:\n%s", message);
            printf("\nThe shifted message before encryption:\n%s", shifted_message);

            coded = encoder(shifted_message, &size, shift_value);

            printf("\nThe encoded message (encrypted by public key):\n");

            for (i = 0; i < size; i++)
            {
                printf("%d\n", coded[i]);
            }

            // Hasil enkripsi disimpan dalam variabel chipertext
            char *chipertext = custom_hash(shifted_message);
            printf("\nHashed ciphertext: %s\n", chipertext);
            free(chipertext); // Jangan lupa untuk membebaskan memori setelah selesai digunakan
            
            break;
        case 2:
            message = (char *)malloc(256 * sizeof(char));
            printf("Masukkan text yang ingin di dekripsi: ");
            getchar();
            fgets(message, 256, stdin); // Membaca input dari pengguna
            clear();

            coded = convertToIntArray(message, &size);

            printf("Masukkan private key untuk pesan ini: ");
            scanf("%d", &private_key);
            getchar();
            clear();

            printf("\nThe decoded message (decrypted by private key):\n");
            decoded = decoder(coded, size - 1, &shift_value);
            printf("The decoded message after decryption: %s\n", decoded);

            // // Lakukan invers shifting pada pesan yang sudah didekripsi
            inversed_shifted_message = shift_message(decoded, -shift_value);
            printf("\nThe decoded message after invers shifting: %s\n", inversed_shifted_message);
	
            break;
        case 3:

        	printf("Terima Kasih ... \n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih 1-3.\n");
        }

    } while (pilihan != 3);

    /*Dealokasi memori*/
    free(coded);
    free(decoded);
    free(message);
    free(shifted_message);
    free(inversed_shifted_message);
    return 0;
}

