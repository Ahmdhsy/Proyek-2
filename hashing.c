#include "hashing.h"


char *custom_hash(char *message) {
    int len = strlen(message);
    char *hashed_message = (char *)malloc((len + 1) * sizeof(char));

    if (hashed_message == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Tabel penggantian atau kunci
    char replacement_table[] = "!@#$%^&*()_+-=[]{}|?~`QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

    // Mengubah setiap karakter pesan menjadi karakter acak dari tabel penggantian
    for (int i = 0; i < len; i++) {
        hashed_message[i] = replacement_table[rand() % strlen(replacement_table)];
    }

    hashed_message[len] = '\0'; // Menambahkan null-terminator

    return hashed_message;
}

