#include "string.h"
#include "main.h"

static char result[1024];

char* message(char* label) {
    strcpy(result, "Hello, ");
    strcat(result, label);
    return result;
}