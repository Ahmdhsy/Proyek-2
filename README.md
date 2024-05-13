# APLIKASI ENCRYPTING MENGGUNAKAN METODE RSA

## DESKRIPSI APLIKASI
Aplikasi ini dibuat untuk memenuhi tugas PROYEK 2 - PENGEMBANGAN APLIKASI BERBASIS LIBRARY.
Aplikasi ini bertujuan untuk mengubah text biasa menjadi sekumpulan text yang tidak bisa dibaca yang disebut cipher text. Selain itu juga aplikasi ini juga bisa mengubah cipher text hasil metode RSA menjadi text biasa kembali yang dapat dibaca.

## INSTALLATION
1. Clone repositori atau download semua file dari repositori.\
2. Install IDE untuk bahasa c/c++ (sangat disarankan menggunakan dev C++)\
3. Buat project baru di dalam IDE DevC++ (Project bertipe console application).\
4. Import semua file berekstensi .c dan .h ke dalam project\
5. Run dan compile project.

## FUNCTION DI DALAM LIBRARY
```c
// Generate bilangan prime ke dalam sebuah array
void generatePrimeNumber()
```

```c
// Generate public key untuk enkripsi
int generatePublicKey()
```

```c
// Generate private key untuk dekripsi
int generatePrivateKey(int publicKey)
```

```c
// Mengenkripsi text atau pesan
int *encoder(char *message, int *size,int shift)
```

```c
// Mendekripsi text atau pesan
char *decoder(int *encoded, int size, int *shift)
```

```c
// Mengenkripsi text atau pesan yang telah melalui RSA menggunakan shifting
char *shift_message(char *message, int shift_value);
```

```c
//Mengenkripsi text atau pesan yang telah melalui RSA dan shifting menggunakan simple hash function
char *custom_hash(char *message);
```

```c
// Function untuk membaca dan menyimpan text ke dalam file
char* readFiles(char *message);
```

```c
// Function tampilan menu
void encryptMenu(int *pilihanEncryptMenu);
```

```c
// Function clear screen setelah input user
void clear();
```

```c
// Function shifting untuk menukar kata pada shifting_word
char *shift_word(char *word, int shift_value);
```

```c
// Function randomizePosition untuk menukar posisi info antar node
void randomizePosition(address *head, address *tail, char *message, int size)
```

```c
// Function insertRandomChar untuk melakukan penyisipan karakter pada node index ganjil setelah melakukan randomizePosisition
void insertRandomChar(address *head, address *tail, char *message)
```

```c
// Function convertLinkedToString untuk mengkonversi linkedlist menjadi array of char (string) agar bisa di proses lebih lanjut pada modul RSA
char *convertLinkedToString(address head_ref);
```

```c
// Function deleteRandomChar untuk menghapus karakter yang tidak seharusnya ada karena fungsi dari insertRandomChar tersebut
void deleteRandomChar(address *head);
```

```c
// Function unrandomizePosition untuk mengembalikan ke urutan pergeseran sebelumnya dan masuk ke invers shifting untuk di kembalikan ke messege awal
void unrandomizePosition(address *head, address *tail, int size);
```



## PEMBAGIAN TUGAS DAN FITUR - CONTRIBUTOR
Pembuatan Metode RSA - Daiva Raditya Pradipa (039) (Username: RaditZX) \
Pembuatan Metode Shifting - Ahmad Fauzan (033) (Username: Ahmdhsy) \
Pembuatan Metode Hashing - Bandyaga Adiansyah Sugandi (037) (Username: basganajaah) \
Pembuatan Menu Aplikasi - Dhea Dria Spralia (040) (Username: dheaasprla) \
Pembuatan Fitur Readfiles hasil Ciphertext - Febytha Putri Nugraheni (046) (Username: DFoerzaaaa) \

## RENCANA TAMPILAN
1. Tampilan awal berisi pilihan menu untuk enkripsi shifting dan RSA
  a. memasukkan text yang ingin di enkripsi
  b. lalu, masukkan nilai pergeseran(shifting)
3. Deskripsi shifting dan RSA
  a. masukkan text yang telah di enkripsi
  b. masukkan private key
5. Enkripsi shifting dan hasing
6. Keluar

Selanjutnya jika memilih salah satu akan menampilkan 
- masukan text
- read file

## ABOUT US
MANAGER:\
Djoko Cahyo Utomo Lieharyani, S.Kom., M.MT. \
NIP 199312282019031013

MEMBER:\
Ahmad Fauzan (NIM:231511033) (Username: Ahmdhsy) \ 
Daiva Raditya Pradipa (NIM:231511039) (Username: RaditZX) \
Bandyaga Adiansyah Sugandi (NIM:231511037) (Username: basganajaah) \
Dhea Dria Spralia (NIM:231511040) (Username: dheaasprla) \
Febytha Putri Nugraheni (NIM:231511046) (Username: DFoerzaaaa)
