#include "RSA.h"

void generatePrimeNumber()
{
    /*Mengenerate bilangan prima dan disimpan pada array primeNumber*/
    for (int i = 2; i < MAX_PRIME; i++)
    {
        int isPrime = 1; // Prediksi awal bahwa i adalah prima

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0; // Jika ditemukan faktor, bukan prima
                break;
            }
        }

        if (isPrime)
        {
            prime[prime_count++] = i;
        }
    }
}

int FPB(int a, int b)
{
    /*Mencari faktor persekutuan terbesar dari dua buah bilangan*/
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int pickrandomprime()
{
    int k = rand() % prime_count;
    int ret = prime[k];
    prime[k] = prime[prime_count - 1];
    prime_count--;
    return ret;
}

int generatePublicKey()
{
    primeNumber1 = pickrandomprime();
    primeNumber2 = pickrandomprime();

    n = primeNumber1 * primeNumber2;
    fi = (primeNumber1 - 1) * (primeNumber2 - 1);
    int e = 3;
    while (FPB(e, fi) != 1)
    {
        e++;
    }

    return e;
}

int generatePrivateKey(int publicKey)
{
    int d = 2;
    while ((d * publicKey) % fi != 1)
    {
        d++;
    }
    return d;
}

long long int encrypt(int message)
{
    int e = public_key;
    long long int encrypted_text = 1;
    for (int i = 0; i < e; i++)
    {
        encrypted_text *= message;
        encrypted_text %= n;
    }
    return encrypted_text;
}

long long int decrypt(int encrypted_text)
{
    int d = private_key;
    long long int decrypted = 1;
    for (int i = 0; i < d; i++)
    {
        decrypted *= encrypted_text;
        decrypted %= n;
    }
    return decrypted;
}

int *encoder(char *message, int *size)
{
    int length = strlen(message);
    int *form = (int *)malloc(length * sizeof(int));
    *size = length;
    for (int i = 0; i < length; i++)
    {
        form[i] = encrypt(message[i]);
    }
    return form;
}

char *decoder(int *encoded, int size)
{
    char *s = (char *)malloc(size + 1);
    for (int i = 0; i < size; i++)
    {
        s[i] = decrypt(encoded[i]);
    }
    s[size] = '\0';
    return s;
}