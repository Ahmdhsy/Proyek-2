#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tLinked *address;
typedef struct tLinked {
    char info;
    address next;
} Linked;

void insertAtBeginning(address *head_ref, char new_data);

// Fungsi untuk menambahkan node baru di tengah linked list
void insertAfter(address prev_node, char new_data);

// Fungsi untuk menambahkan node baru di akhir linked list
void insertAtEnd(address *head_ref, char new_data);

void printList(address node);

#endif 
