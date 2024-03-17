#ifndef CLS_H
#define CLS_H

#include <stdio.h>

#ifdef _WIN32 // Memeriksa OS Windows
    #include <stdlib.h>
    #define CLEAR_SCREEN "cls" // Clear screen di Windows
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear" // Clear screen di Unix-like systems
#endif

void clear();

#endif
