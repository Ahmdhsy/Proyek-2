#include "Shifting.h"
#include <time.h>

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

void randomizePosition(address *head, address *tail, char *message, int size)
{
    for (int i = 0; i < size; i++)
    {
        insertAtEnd(head, tail, message[i]);
    }

    address pNode = *head;
    address pLast = *tail;

    for (int i = 1; i < size / 2 - 1; i++)
    {
        if (pNode != NULL && pNode->next != NULL)
        {
            address temp = pNode->next;

            char temp_info = pNode->info;
            pNode->info = temp->info;
            temp->info = temp_info;

            pNode = temp->next;
        }
        if (pNode != NULL && pNode->prev != NULL)
        {

            address temp = pLast->prev;

            char temp_info = pLast->info;
            pLast->info = temp->info;
            temp->info = temp_info;

            pLast = temp->prev;
        }
    }

    printf("Linked List setelah randomisasi: \n");
    printList(*head);
}

void insertRandomChar(address *head, address *tail, char *message, int size)
{
    srand(time(NULL));
    char replacement_table[] = "~`QWOP()_+-=[]{}|?NMqwertYUIASERTiopasfghXCVB!@#DFGHJKLZyujkld$%^&*zxcvbnm1234567890";

    address pNode = *head;

    while (pNode != NULL)
    {
        if (pNode->prev != NULL)
        {
            int charChoice = rand() % strlen(replacement_table);
            insertAfter(pNode->prev, replacement_table[charChoice]);
        }
        pNode = pNode->next;
    }

    printf("Linked List setelah insert random char: \n");
    printList(*head);
}

// versi sebelumnya

// void insertRandomChar(address **head, address **tail, char *message, int size)
//{
//     srand(time(NULL));
//     char replacement_table[] = "~`QWOP()_+-=[]{}|?NMqwertYUIASERTiopasfghXCVB!@#DFGHJKLZyujkld$%^&*zxcvbnm1234567890";
//
//
//	address pNode = *head;
//	address pTail = *tail;
//	int i;
//
//     while(pNode != NULL)
//     {
//     	i=1;
//         if (i % 2 != 0)
//         {
//			address temp = pNode;
//			pNode=pNode->next;
//             int charChoice = rand() % strlen(replacement_table);
//             insertAfter(temp, replacement_table[charChoice]);
//         }
//         i++;
//     }
//
//     printf("Linked List setelah insert random char: \n");
//     printList(*head);
// }
