#include "RSA.h"

int prime[MAX_PRIME];
int prime_count;

int public_key;
int private_key;
int n;
int primeNumber1, primeNumber2, fi;

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

int gcd(int a, int b)
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

int pickRandomPrime()
{

    srand(time(NULL));
    int k = rand() % prime_count;
    int ret = prime[k];
    prime[k] = prime[prime_count - 1];
    prime_count--;
    return ret;
}

int generatePublicKey()
{
    primeNumber1 = pickRandomPrime();
    primeNumber2 = pickRandomPrime();

    n = primeNumber1 * primeNumber2;
    fi = (primeNumber1 - 1) * (primeNumber2 - 1);

    int e = 3;
    while (gcd(e, fi) != 1)
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

int encrypt(int message)
{
    if (message < 0 || message >= n)
    {
        printf("Error: Invalid message for encryption.\n");
        exit(1);
    }

    int e = public_key;
    int encrypted_text = 1;
    for (int i = 0; i < e; i++)
    {
        encrypted_text *= message;
        encrypted_text %= n;
    }
    return encrypted_text;
}

int decrypt(int encrypted_text)
{

    int d = private_key;

    int decrypted = 1;
    for (int i = 0; i < d; i++)
    {

        decrypted *= encrypted_text;
        decrypted %= n;
    }

    return decrypted;
}

int *encoder(char *message, int *size,int shift)
{
    int length = strlen(message);
    int *form = (int *)malloc((length + 2) * sizeof(int)); // Allocate one extra space for size

    if (form == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Store the size of the message in the first element
	form[0] = n;
	form[length + 1] = shift;
	
    for (int i = 0; i < length; i++)
    {
        form[i+1] = encrypt(message[i]);
    }
    *size = length + 2; // Update size including the size information
    return form;
}

int *convertToIntArray(char *str, int *size)
{
    int *array = NULL;
    int count = 0;

    // Mencari tahu berapa banyak angka yang ada dalam string
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    // Alokasi memori untuk array integer
    array = (int *)malloc((count + 1) * sizeof(int)); // Menambahkan 1 untuk menyimpan ukuran array
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Mengonversi string menjadi array integer
    char *token = strtok(str, " "); // Menggunakan spasi sebagai pemisah
    int index = 0;
    while (token != NULL)
    {
        array[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Menyimpan ukuran array
    *size = index;

    return array;
}

char *decoder(int *encoded, int size, int *shift)
{

    n = encoded[0];
    *shift = encoded[size-1]; // Retrieve shift from the last element

    char *s = (char *)malloc((size - 2) * sizeof(char)); // Exclude size and shift

    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < size - 2; i++)
    {
        s[i] = (char)decrypt(encoded[i + 1]);
    }
    s[size - 2] = '\0'; // Null-terminate the string

    return s;
}

