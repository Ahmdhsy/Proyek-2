#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tLinked *address;
typedef struct tLinked
{
    char info;
    address next, prev;
} Linked;

void insertAtBeginning(address *head_ref,address *tail, char new_data);

// Fungsi untuk menambahkan node baru di tengah linked list
void insertAfter(address prev_node, char new_data);

// Fungsi untuk menambahkan node baru di akhir linked list
void insertAtEnd(address *head_ref,address *tail, char new_data);

void deleteAtBeginning(address *head_ref, address *tail);

void deleteAtEnd(address *head_ref, address *tail);

void deleteAfter(address prev_node);

void printList(address node);

char *convertLinkedToString(address head_ref);

#endif
