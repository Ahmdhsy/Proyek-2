#include "RSA.c"

int main()
{
    generatePrimeNumber();
    public_key = generatePublicKey();
    private_key = generatePrivateKey(public_key);

    char *message = (char *)malloc(100 * sizeof(char)); // Alokasi memori

    if (message == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // retrun true
    }
    
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Masukkan text yang ingin dienkripsi: ");
    fgets(message, 100, stdin);

    int size;
    int *coded = encoder(message, &size);
    printf("\nInitial message:\n%s", message);
    printf("\nThe encoded message (encrypted by public key)\n");
    
    for (int i = 0; i < size; i++)
    {
        printf("%d", coded[i]);
    }
    
    printf("\n\nThe decoded message (decrypted by private key)\n");
    char *decoded = decoder(coded, size);
    printf("%s", decoded);

    free(coded);
    free(decoded);

    return 0;
}
