#include "RSA.h"

int main()
{
    int size;
    int *coded;
    char *message, *decoded;

    generatePrimeNumber();
    public_key = generatePublicKey();
    private_key = generatePrivateKey(public_key);

    // Allocate memory for a string with a buffer that can handle larger input
    message = (char *)malloc(256 * sizeof(char));

    if (message == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Masukkan text: ");
    fgets(message, 256, stdin);

    // Ensure the input string has a newline character at the end
    if (strlen(message) > 0 && message[strlen(message) - 1] != '\n')
    {
        while (getchar() != '\n'); // Clear the input buffer
    }

    coded = encoder(message, &size);

    printf("Initial message:\n%s", message);
    printf("\nThe encoded message (encrypted by public key):\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", coded[i]);  // Separate numbers with space
    }

    printf("\n\nThe decoded message (decrypted by private key):\n");
    decoded = decoder(coded, size);
    printf("%s\n", decoded);

    free(coded);
    free(decoded);
    free(message); // Don't forget to free the allocated memory for the message
    return 0;
}

