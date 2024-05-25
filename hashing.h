#ifndef HASHING_H
#define HASHING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shifting.h"

#define MAX_LEN 1000

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void customEncrypt(const char *plaintextHash, char *ciphertextHash, int *randomValues, const char *replacementTable);
void customDecrypt(const char *ciphertextHash, char *plaintextHash, const int *randomValues, const char *replacementTable, const char *spaceSymbols, int numSymbols);
struct Node* createNode(char data);
void freeLinkedList(struct Node* head);
struct Node* arrayToLinkedList(const char *array);
void linkedListToArray(struct Node* head, char *array);
void printLinkedList(struct Node* head);
void addRandomCharacter(struct Node* head, const char *replacementTable);
void deleteRandomCharacter(struct Node* head);
char replaceSpace();
int menuHashing();

#endif

