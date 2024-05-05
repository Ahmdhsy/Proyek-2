#ifndef SHIFTING_H
#define SHIFTING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

char *shift_message(char *message, int shift_value);
void randomizePosition(address **head,char *message, int size);
void unrandomizePosition(char *message, int size);
void insertRandomChar(address **head,char *message, int size);

#endif
