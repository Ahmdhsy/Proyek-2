#include "Shifting.h"


char *shift_message(char *message, int shift_value)
{
    int length = strlen(message);

    char *shifted_message = (char *)malloc((length + 1) * sizeof(char));

    if (shifted_message == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < length; i++)
    {
        char current_char = message[i];
        if (current_char >= 'a' && current_char <= 'z')
        {                                                                       // Jika karakter huruf kecil
            shifted_message[i] = 'a' + (current_char - 'a' + shift_value) % 26; // Geser karakter sesuai dengan nilai pergeseran, menghindari pergeseran melampaui 'z'
        }
        else if (current_char >= 'A' && current_char <= 'Z')
        {                                                                       // Jika karakter huruf besar
            shifted_message[i] = 'A' + (current_char - 'A' + shift_value) % 26; // Geser karakter sesuai dengan nilai pergeseran, menghindari pergeseran melampaui 'Z'
        }
        else
        { // Jika bukan huruf, biarkan karakter tetap
            if (current_char >= 'a' && current_char <= 'z')
            {
                shifted_message[i] = 'a' + (current_char - 'a' + shift_value + 26) % 26;
            }
            else if (current_char >= 'A' && current_char <= 'Z')
            {
                shifted_message[i] = 'A' + (current_char - 'A' + shift_value + 26) % 26;
            }
            else
            {
                shifted_message[i] = current_char;
            }
        }
    }

    shifted_message[length] = '\0'; // Tambahkan terminasi string pada akhir pesan
    shifted_message[length] = '\0';
    return shifted_message;

    free(shifted_message);
}

void randomizePosition(address **head, char *message, int size) {
    srand(time(NULL)); // Seed srand only once

    for (int i = 0; i < size; i++) {
        int angka = rand() % 3; // Generate random number from 0 to 2

        if (*head == NULL) {
            insertAtBeginning(head, message[i]);
            continue;
        }

        switch (angka) {
            case 0:
                insertAtBeginning(head, message[i]);
                break;
            case 1:
                insertAfter(head, message[i]);
                break;
            case 2:
                insertAtEnd(head, message[i]);
                break;
        }
    }

    printf("Linked List setelah randomisasi: \n");
    printList(*head);
}

void insertRandomChar(address **head, char *message, int size) {
    srand(time(NULL)); // Seed srand only once
    char replacement_table[] = "!@#$%^&*()_+-=[]{}|?~`QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

    for (int i = 0; i < size; i++) {
        int angka = rand() % 3; // Generate random number from 0 to 2
        int charChoice = rand() % strlen(replacement_table);

        if (*head == NULL) {
            insertAtBeginning(head, replacement_table[charChoice]);
            continue;
        }

        switch (angka) {
            case 0:
                insertAtBeginning(head, replacement_table[charChoice]);
                break;
            case 1:
                insertAfter(head, replacement_table[charChoice]);
                break;
            case 2:
                insertAtEnd(head, replacement_table[charChoice]);
                break;
        }
    }

    printf("Linked List setelah insert random char: \n");
    printList(*head);
}

