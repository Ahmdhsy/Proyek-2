#include "RSA.h"

int main()
{
    int size;
    int *coded;
    char *message, *decoded;

    generatePrimeNumber();
    public_key = generatePublicKey();
    private_key = generatePrivateKey(public_key);
	
	printf("This is public key: %d\n", public_key);
	printf("This is private key: %d\n", private_key);
	
    message = (char *)malloc(256 * sizeof(char));

    if (message == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // return true
    }

    printf("Masukkan text yang ingin di enkripsi: ");
    fgets(message, 256, stdin);

    if (strlen(message) > 0 && message[strlen(message) - 1] != '\n')
    {
        while (getchar() != '\n');
    }

    // Lakukan shifting pesan sebelum enkripsi
    int shift_value;
    printf("Masukkan nilai pergeseran untuk shifting pesan: ");
    scanf("%d", &shift_value);
    getchar(); // Tangkap newline character yang tersisa setelah input

    char *shifted_message = shift_message(message, shift_value);

    printf("Initial message:\n%s", message);
    printf("\nThe shifted message before encryption:\n%s", shifted_message);

    coded = encoder(shifted_message, &size);

    printf("\nThe encoded message (encrypted by public key):\n");
	
	int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", coded[i]); 
    }

    printf("\n\nThe decoded message (decrypted by private key):\n");
    decoded = decoder(coded, size);
    printf("The decoded message after decryption: %s\n", decoded);

    // Lakukan invers shifting pada pesan yang sudah didekripsi
    char *inversed_shifted_message = shift_message(decoded, -shift_value);
    printf("\nThe decoded message after invers shifting: %s\n", inversed_shifted_message);

    free(coded);
    free(decoded);
    free(message);
    free(shifted_message);
    free(inversed_shifted_message);
    return 0;
}

