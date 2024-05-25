#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *readFiles(char *fileName) {
    FILE *file = fopen(fileName, "r");
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

//char *readPdfFile(char *fileName) {
//    PopplerDocument *document;
//    GError *error = NULL;
//    char *content = NULL;
//    int num_pages, i;
//    size_t length = 0;
//
//    document = poppler_document_new_from_file(fileName, NULL, &error);
//    if (error != NULL) {
//        g_error_free(error);
//        perror("Failed to open the PDF file");
//        return NULL;
//    }
//
//    num_pages = poppler_document_get_n_pages(document);
//    for (i = 0; i < num_pages; i++) {
//        PopplerPage *page = poppler_document_get_page(document, i);
//        char *page_text = poppler_page_get_text(page);
//        length += strlen(page_text);
//        content = realloc(content, length + 1);
//        strcat(content, page_text);
//        g_free(page_text);
//        g_object_unref(page);
//    }
//
//    g_object_unref(document);
//
//    return content;
//}
//
//char *readWordFile(char *fileName) {
//    LibreOfficeKit *kit;
//    LibreOfficeKitDocument *doc;
//    char *content = NULL;
//
//    kit = libreofficekit_construct("path/to/libreoffice/program");
//    if (!kit) {
//        perror("Failed to initialize LibreOfficeKit");
//        return NULL;
//    }
//
//    doc = libreofficekit_document_load(kit, fileName);
//    if (!doc) {
//        perror("Failed to open the Word file");
//        libreofficekit_destroy(kit);
//        return NULL;
//    }
//
//    const char *textCStr = libreofficekit_document_to_text(doc, NULL);
//    if (textCStr) {
//        content = strdup(textCStr);
//    }
//
//    libreofficekit_document_close(doc);
//    libreofficekit_destroy(kit);
//
//    return content;
//}
//
//char *readFiles(char *fileName) {
//    char *content = NULL;
//    const char *extension = strrchr(fileName, '.');
//    if (extension != NULL) {
//        if (strcmp(extension, ".txt") == 0) {
//            content = readTxtFile(fileName);
//        } else if (strcmp(extension, ".pdf") == 0) {
//            content = readPdfFile(fileName);
//        } else if (strcmp(extension, ".doc") == 0 || strcmp(extension, ".docx") == 0) {
//            content = readWordFile(fileName);
//        } else {
//            printf("Unsupported file format.\n");
//        }
//    } else {
//        printf("File format not recognized.\n");
//    }
//
//    return content;
//}


