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
void menu();
void encryptMenu(int *pilihanEncryptMenu);
```

```c
// Function clear screen setelah input user
void clear();
```

## PEMBAGIAN TUGAS DAN FITUR - CONTRIBUTOR
Pembuatan Metode RSA - Daiva Raditya Pradipa (039) (Username: RaditZX) (Branch :  RSA-Flow)\
Pembuatan Metode Shifting - Ahmad Fauzan (033) (Username: Ahmdhsy) \
Pembuatan Metode Hashing - Bandyaga Adiansyah Sugandi (037) (Username: basganajaah) \
Pembuatan Menu Aplikasi - Dhea Dria Spralia (040) (Username: dheaasprla) \
Pembuatan Fitur Readfiles dan Writefiles hasil Ciphertext - Febytha Putri Nugraheni (046) (Username: DFoerzaaaa)\

## RENCANA TAMPILAN


## ABOUT US
MANAGER:\
Djoko Cahyo Utomo Lieharyani, S.Kom., M.MT. \
NIP 199312282019031013

LEADER:\
Ahmad Fauzan (NIM:231511033) (Username: Ahmdhsy) 
MEMBER:\
Daiva Raditya Pradipa (NIM:231511039) (Username: RaditZX)\
Bandyaga Adiansyah Sugandi (NIM:231511037) (Username: basganajaah) \
Dhea Dria Spralia (NIM:231511040) (Username: dheaasprla) \
Febytha Putri Nugraheni (NIM:231511046) (Username: DFoerzaaaa)
