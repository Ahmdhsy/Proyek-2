#include "RSA.c"

int main()
{
    generatePrimeNumber();
    public_key = generatePublicKey();
    private_key = generatePrivateKey(public_key);

    char *message = (char *)malloc(100 * sizeof(char)); // Allocate memory for a string

    if (message == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }
    printf("%d", public_key);
    printf("%d", private_key);
    printf("Masukkan text: ");
    scanf("%s", message);

    int size;
    int *coded = encoder(message, &size);
    printf("Initial message:\n%s", message);
    printf("\n\nThe encoded message(encrypted by public key)\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", coded[i]);
    }
    printf("\n\nThe decoded message(decrypted by private key)\n");
    char *decoded = decoder(coded, size);
    printf("%s\n", decoded);

    free(coded);
    free(decoded);
    return 0;
}
