#ifndef RSA_H
#define RSA_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "hashing.h"
// #include <openssl/sha.h>

#define MAX_PRIME 250


extern int prime[MAX_PRIME];
extern int prime_count;

extern int public_key;
extern int private_key;
extern int n;
extern int primeNumber1, primeNumber2, fi;

void generatePrimeNumber();
int gcd(int a, int b);
int pickrandomprime();
int generatePublicKey();
int generatePrivateKey(int publicKey);
int encrypt(int message);
int decrypt(int encrypted_text);
int *encoder(char *message, int *size, int shift);
int *convertToIntArray(char *str, int *size);
char *decoder(int *encoded, int size, int *shift);

#endif
