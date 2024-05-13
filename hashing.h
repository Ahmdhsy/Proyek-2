#ifndef HASHING_H
#define HASHING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"

#define MAX_LEN 1000

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};
  
void customEncrypt(const char *plaintextHash, char *ciphertextHash, int *randomValues);
void customDecrypt(const char *ciphertextHash, char *plaintextHash, const int *randomValues);
int menuHashing();

#endif

