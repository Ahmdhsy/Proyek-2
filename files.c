#include "files.h"

char *readFiles(char *fileName) {
  	FILE *file;
  	file = fopen(fileName, "r");
    if (file == NULL) {
         perror("Failed to open the file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(length + 1);
    if (content == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    fread(content, 1, length, file);
    content[length] = '\0';

    fclose(file);

    return content;
}

