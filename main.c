#include "RSA.h"
#include "Shifting.h"
#include "menu.h"
#include "files.h"
#include "cls.h"
#include "hashing.h"
#include "linkedlist.h"

int main()
{
    int size, i, pilihan, pilihanEncryptMenu, shift_value;
    int *coded;
    char *message, *decoded, *inversed_shifted_message, *fileName;
    char *shifted_message;
    char *chiperText;
    address head = NULL;
    address tail = NULL;

    pilihanEncryptMenu = 0;
    do
    {
        menu();
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        clear();
        switch (pilihan)
        {
        case 1:
            encryptMenu(&pilihanEncryptMenu, "encrypt");
            generatePrimeNumber();
            public_key = generatePublicKey();
            private_key = generatePrivateKey(public_key);

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
                fileName = (char *)malloc(256 * sizeof(char));
                printf("Masukkan nama file (ex:text.txt): ");
                getchar();
                scanf("%255s", fileName);
                message = readFiles(fileName);
                free(fileName);
            }

            printf("Masukkan nilai pergeseran untuk shifting pesan: ");
            scanf("%d", &shift_value);
            getchar();
            clear();

            printf("This is public key: %d\n", public_key);
            printf("This is private key: %d\n", private_key);

            shifted_message = shift_message(message, shift_value);

            printf("\nInitial message:\n%s", message);
            printf("\nThe shifted message before encryption:\n%s", shifted_message);
            randomizePosition(&head,&tail, shifted_message, strlen(shifted_message) - 1);
            insertRandomChar(&head,&tail, shifted_message, strlen(shifted_message) - 1);
            coded = encoder(shifted_message, &size, shift_value);

            printf("\nThe encoded message (encrypted by public key):\n");

            for (i = 0; i < size; i++)
            {
                printf("%d ", coded[i]);
            }
            printf("\n\nPress enter to continue...");
            getchar();
            clear();
            break;
        case 2:
            encryptMenu(&pilihanEncryptMenu, "decrypt");
            message = (char *)malloc(256 * sizeof(char));
            if (pilihanEncryptMenu == 1)
            {
                printf("Masukkan text yang ingin di dekripsi: ");
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
                fileName = (char *)malloc(256 * sizeof(char)); // Allocate memory for fileName
                printf("Masukkan nama file (ex:text.txt): ");
                getchar();
                scanf("%255s", fileName);
                message = readFiles(fileName);
                free(fileName);
            }

            coded = convertToIntArray(message, &size);

            printf("Masukkan private key untuk pesan ini: ");
            scanf("%d", &private_key);
            getchar();
            clear();

            printf("\nThe decoded message (decrypted by private key):\n");
            decoded = decoder(coded, size, &shift_value);
            printf("The decoded message after decryption: %s\n", decoded);

            inversed_shifted_message = shift_message(decoded, -shift_value);
            printf("\nThe decoded message after invers shifting: %s\n", inversed_shifted_message);

            printf("\nPress enter to continue...");
            getchar();
            clear();
            break;
        case 3:
            encryptMenu(&pilihanEncryptMenu, "encrypt");
            generatePrimeNumber();
            public_key = generatePublicKey();
            private_key = generatePrivateKey(public_key);

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
                fileName = (char *)malloc(256 * sizeof(char)); // Allocate memory for fileName
                printf("Masukkan nama file (ex:text.txt): ");
                getchar();
                scanf("%255s", fileName);
                message = readFiles(fileName);
                free(fileName);
            }

            printf("Masukkan nilai pergeseran untuk shifting pesan: ");
            scanf("%d", &shift_value);
            getchar(); // Capture the newline character left after the input
            clear();

            printf("This is public key: %d\n", public_key);
            printf("This is private key: %d\n", private_key);

            shifted_message = shift_message(message, shift_value);

            printf("\nInitial message:\n%s", message);
            printf("\nThe shifted message before encryption:\n%s", shifted_message);
            // Hash
            chiperText = custom_hash(shifted_message);
            printf("\nHashed ciphertext: %s\n", chiperText);

            printf("\nPress enter to continue...");
            getchar();
            clear();
            break;
        case 4:
            printf("Terima Kasih ... \n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih 1-3.\n");
        }


    } while (pilihan != 3);

    free(message);
    free(coded);
    free(shifted_message);
    free(decoded);
    free(inversed_shifted_message);
    free(chiperText);
    
    return 0;

}


