#include "lsb.h"

// Function to duplicate a string
char *my_strdup(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    size_t len = strlen(str) + 1;
    char *dup_str = (char *)malloc(len);

    if (dup_str != NULL)
    {
        strcpy(dup_str, str);
    }

    return dup_str;
}

void hideTextInPNG(const char *inputImage, const char *outputImage, const char *text)
{
    int width, height, bpp;
    unsigned char *image = stbi_load(inputImage, &width, &height, &bpp, CHANNELS);

    if (image == NULL)
    {
        printf("Error loading the image.\n");
        exit(1);
    }

    // Use a writable buffer for text
    char *textBuffer = my_strdup(text);
    if (textBuffer == NULL)
    {
        printf("Error allocating memory for text buffer.\n");
        stbi_image_free(image);
        exit(1);
    }

    int textIndex = 0;
    int textLength = strlen(textBuffer);
    int totalBits = textLength * 8;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixelIndex = (y * width + x) * CHANNELS;

            for (int c = 0; c < CHANNELS; c++)
            {
                if (textIndex < totalBits)
                {
                    // Clear the LSB and set it to the corresponding bit of the text
                    image[pixelIndex + c] &= 0xFE;
                    image[pixelIndex + c] |= (textBuffer[textIndex / 8] >> (7 - (textIndex % 8))) & 1;
                    textIndex++;
                }
            }
        }
    }

    stbi_write_png(outputImage, width, height, CHANNELS, image, width * CHANNELS);

    stbi_image_free(image);
    free(textBuffer);

    printf("Text hidden successfully in PNG.\n");
}

char *retrieveTextFromPNG(const char *imagePath)
{
    int width, height, bpp;
    unsigned char *image = stbi_load(imagePath, &width, &height, &bpp, CHANNELS);

    if (image == NULL)
    {
        printf("Error loading the image.\n");
        exit(1);
    }

    // Allocate memory for the text buffer
    char *textBuffer = (char *)malloc((width * height * CHANNELS / 8) + 1);
    if (textBuffer == NULL)
    {
        printf("Error allocating memory for text buffer.\n");
        stbi_image_free(image);
        exit(1);
    }

    int textIndex = 0;
    char currentChar = 0;
    int bitCount = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixelIndex = (y * width + x) * CHANNELS;

            for (int c = 0; c < CHANNELS; c++)
            {
                currentChar |= (image[pixelIndex + c] & 1) << (7 - bitCount);
                bitCount++;

                if (bitCount == 8)
                {
                    textBuffer[textIndex++] = currentChar;
                    if (currentChar == '\0')
                    {
                        textBuffer[textIndex] = '\0';
                        stbi_image_free(image);
                        return textBuffer;
                    }
                    currentChar = 0;
                    bitCount = 0;
                }
            }
        }
    }

    // Null-terminate the text buffer
    textBuffer[textIndex] = '\0';

    stbi_image_free(image);

    return textBuffer;
}


