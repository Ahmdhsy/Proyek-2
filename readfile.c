#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readfile() {
    FILE *file;
    char *text;
    long length;

    // Buka file untuk dibaca
    file = fopen("file.txt", "r");

    // Periksa apakah file berhasil dibuka
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Hitung panjang file
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Alokasi memori dinamis untuk menyimpan teks
    text = (char*) malloc(length + 1);

    // Periksa apakah alokasi memori berhasil
    if (text == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    // Baca teks dari file dan simpan dalam variabel
    fread(text, 1, length, file);
    text[length] = '\0'; // Tambahkan null-terminator pada akhir teks

    // Tampilkan teks yang telah dibaca
    printf("Teks dari file:\n%s\n", text);

    // Memasukkan teks yang dibaca ke dalam variabel baru
    char *myText = (char*) malloc(length + 1);
    strcpy(myText, text); // Menyalin teks dari text ke myText


    // Tampilkan teks yang telah disalin ke dalam variabel baru
    printf("Teks dalam variabel baru:\n%s\n", myText);

    // Bebaskan memori dan tutup file
    free(text);
    fclose(file);

    return 0;
}