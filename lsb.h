#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define CHANNELS 4

char *my_strdup(const char *str);

void hideTextInPNG(const char *inputImage, const char *outputImage, const char *text);

char *retrieveTextFromPNG(const char *imagePath);

