#ifndef RSA_H
#define RSA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include <openssl/sha.h>

#define MAX_PRIME 250

int prime[MAX_PRIME];
int prime_count = 0;

int public_key;
int private_key;
int n;
int primeNumber1, primeNumber2, fi;

void generatePrimeNumber();
int FPB(int a, int b);
int pickrandomprime();
int generatePublicKey();
int generatePrivateKey(int publicKey);
long long int encrypt(int message);
long long int decrypt(int encrypted_text);
int *encoder(char *message, int *size);
char *decoder(int *encoded, int size);

#endif