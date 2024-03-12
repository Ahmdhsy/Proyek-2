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
