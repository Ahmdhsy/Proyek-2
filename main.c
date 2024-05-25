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
    char *randomizeMessage, *unRandomizeMessage;
    char *message = NULL, *decoded = NULL, *inversed_shifted_message = NULL, *fileName = NULL;
    char *shifted_message = NULL;
    char *chiperText = NULL;
    char *hiddenText = NULL;
    char *imageName = NULL;
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
            randomizeMessage = (char *)malloc(256 * sizeof(char));

            if (pilihanEncryptMenu == 1)
            {
                printf("Masukkan text yang ingin di enkripsi: ");
                getchar();
                fgets(message, 256, stdin);
                clear();
                message[strcspn(message, "\n")] = '\0';
            }
            else if (pilihanEncryptMenu == 2)
            {
                fileName = (char *)malloc(256 * sizeof(char));
                printf("Masukkan nama file (ex:text.txt): ");
                getchar();
                fgets(fileName, 256, stdin);
                fileName[strcspn(fileName, "\n")] = '\0';
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
            randomizePosition(&head, &tail, shifted_message, strlen(shifted_message));
        	printf("Linked List setelah randomisasi: \n");
    		printList(head);
            insertRandomChar(&head);      
		    printf("Linked List setelah insert random char: \n");
		    printList(head);
		    randomizeMessage = convertLinkedToString(head);
            coded = encoder(randomizeMessage, &size, shift_value);

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
            unRandomizeMessage = (char *)malloc(256 * sizeof(char));
            if (pilihanEncryptMenu == 1)
            {
                printf("Masukkan text yang ingin di dekripsi: ");
                getchar();
                fgets(message, 256, stdin);
                clear();
                message[strcspn(message, "\n")] = '\0';
            }
            else if (pilihanEncryptMenu == 2)
            {
                fileName = (char *)malloc(256 * sizeof(char));
                printf("Masukkan nama file (ex:text.txt): ");
                getchar();
                fgets(fileName, 256, stdin);
                fileName[strcspn(fileName, "\n")] = '\0';
                message = readFiles(fileName);
                free(fileName);
            }

            coded = convertToIntArray(message, &size);

            printf("Masukkan private key untuk pesan ini: ");
            scanf("%d", &private_key);
            getchar();
            clear();

            decoded = decoder(coded, size, &shift_value);
            printf("The decoded message after RSA decryption: %s\n", decoded);
			head = convertStringToDoublyLinkedList(decoded);
			deleteRandomChar(&head, &tail, &size);
			address plast = head;
			while (plast != NULL && plast->next != NULL) {
			    plast = plast->next;
			}
			unrandomizePosition(&head, &plast, size);
			unRandomizeMessage = convertLinkedToString(head);
			

            inversed_shifted_message = shift_message(unRandomizeMessage, -shift_value);
            printf("\nThe decoded message after invers shifting: %s\n", inversed_shifted_message);

            printf("\nPress enter to continue...");
            getchar();
            clear();
            free(head);
            break;
        case 3:
            menuHashing();
            printf("\nTekan ENTER untuk continue...");
            getchar();
            clear();
            break;

        case 4:
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
                message[strcspn(message, "\n")] = '\0';
            }
            else if (pilihanEncryptMenu == 2)
            {
                fileName = (char *)malloc(256 * sizeof(char));
                printf("Masukkan nama file (ex:text.txt): ");
                getchar();
                fgets(fileName, 256, stdin);
                fileName[strcspn(fileName, "\n")] = '\0';
                message = readFiles(fileName);
                free(fileName);
            }

            printf("Masukkan nilai pergeseran untuk shifting pesan: ");
            scanf("%d", &shift_value);
            getchar();
            clear();

            shifted_message = shift_message(message, shift_value);

            printf("\nInitial message:\n%s", message);
            printf("\nThe shifted message before encryption to LSB:\n%s", shifted_message);

            char *inputImage = "sample1.png";
            char *outputImage = (char *)malloc(256 * sizeof(char));

            printf("Masukkan nama output image (ex: image.png): ");
            fgets(outputImage, 256, stdin);
            outputImage[strcspn(outputImage, "\n")] = '\0';

            clear();
            printf("Output image: %s\n", outputImage);
            hideTextInPNG(inputImage, outputImage, shifted_message);

            system("pause");
            free(outputImage);
            break;
        case 5:
            imageName = (char *)malloc(256 * sizeof(char));
            printf("Masukkan nama image (ex: image.png): ");
            getchar();
            fgets(imageName, 256, stdin);
            imageName[strcspn(imageName, "\n")] = '\0';
            clear();

            printf("image: %s\n", imageName);

            hiddenText = retrieveTextFromPNG(imageName);

            for (int i = 0; i < 10; i++)
            {
                printf("%c", hiddenText[i]);
            }

            printf("\n");

            printf("Masukkan nilai pergeseran untuk unshifting pesan: ");
            scanf("%d", &shift_value);
            getchar();
            clear();
            inversed_shifted_message = shift_message(hiddenText, -shift_value);
            printf("The decoded message after invers shifting:\n");
            for (int i = 0; i < 50; i++)
            {
                printf("%c", inversed_shifted_message[i]);
            }

            printf("\nPress enter to continue...");
            getchar();
            clear();
            free(imageName);
            free(hiddenText);
            break;
        case 6:
            printf("Terima Kasih ... \n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih 1-6.\n");
        }

    } while (pilihan != 6);

    // Free the pointers
    free(coded);
    free(message);
    free(decoded);
    free(inversed_shifted_message);
    free(fileName);
    free(shifted_message);
    free(chiperText);
    free(hiddenText);
    free(imageName);

    // Set pointers to NULL after freeing to avoid dangling pointers
    coded = NULL;
    message = NULL;
    decoded = NULL;
    inversed_shifted_message = NULL;
    fileName = NULL;
    shifted_message = NULL;
    chiperText = NULL;
    hiddenText = NULL;
    imageName = NULL;

    return 0;
}
