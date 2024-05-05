#include "linkedlist.h"

// Fungsi untuk menambahkan node baru di awal linked list
void insertAtBeginning(address *head_ref, char new_data) {
    address new_node = (address)malloc(sizeof(Linked));
    new_node->info = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Fungsi untuk menambahkan node baru di tengah linked list
void insertAfter(address prev_node, char new_data) {
    if (prev_node == NULL) {
        printf("Node sebelumnya tidak boleh NULL");
        return;
    }
    address new_node = (address)malloc(sizeof(Linked));
    new_node->info = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Fungsi untuk menambahkan node baru di akhir linked list
void insertAtEnd(address *head_ref, char new_data) {
    address new_node = (address)malloc(sizeof(Linked));
    address last = *head_ref;
    new_node->info = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(address node) {
    while (node != NULL) {
        printf("%c ", node->info);
        node = node->next;
    }
}

