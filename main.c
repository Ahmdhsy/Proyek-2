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

    coded = encoder(message, &size);

    printf("Initial message:\n%s", message);
    printf("\nThe encoded message (encrypted by public key):\n");
	
	int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", coded[i]); 
    }

    printf("\n\nThe decoded message (decrypted by private key):\n");
    decoded = decoder(coded, size);
    printf("%s\n", decoded);

    free(coded);
    free(decoded);
    free(message);
    return 0;
}
