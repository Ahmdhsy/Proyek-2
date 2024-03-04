#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define CHANNELS 4

// Function to duplicate a string
char *my_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str) + 1;
    char *dup_str = (char *)malloc(len);

    if (dup_str != NULL) {
        strcpy(dup_str, str);
    }

    return dup_str;
}

void hideTextInPNG(const char *inputImage, const char *outputImage, const char *text) {
    int width, height, bpp;
    unsigned char *image = stbi_load(inputImage, &width, &height, &bpp, CHANNELS);

    if (image == NULL) {
        printf("Error loading the image.\n");
        exit(1);
    }

    // Use a writable buffer for text
    char *textBuffer = my_strdup(text);
    if (textBuffer == NULL) {
        printf("Error allocating memory for text buffer.\n");
        exit(1);
    }

    int textIndex = 0;
    for (int i = 0; i < width * height * CHANNELS; i++) {
        if (textBuffer[textIndex] == '\0') {
            break;
        }

        image[i] &= 0xFE; // Clear the LSB
        image[i] |= (textBuffer[textIndex] >> 7) & 1; // Set the MSB of the text bit
        textBuffer[textIndex] <<= 1; // Shift to the next bit

        if (i % CHANNELS == CHANNELS - 1) {
            textIndex++;
        }
    }

    stbi_write_png(outputImage, width, height, CHANNELS, image, width * CHANNELS);

    stbi_image_free(image);
    free(textBuffer);

    printf("Text hidden successfully in PNG.\n");
}

int main() {
    const char *inputImage = "anime-png-24.png";
    const char *outputImage = "output1.png";
    const char *textToHide = "Hello, this is a secret message!";

    hideTextInPNG(inputImage, outputImage, textToHide);

    return 0;
}

