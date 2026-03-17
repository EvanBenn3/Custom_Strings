#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int my_strtok(char ***tokens, char *string, char del) {
    int ptr = 0;
    int strptr = 0;
    int tokptr = 0;
    (*tokens) = realloc((*tokens), sizeof(char*));
    (*tokens)[tokptr] = NULL;
    while (string[ptr] != 0) {
        if (string[ptr] == del) {
            (*tokens)[tokptr] = realloc((*tokens)[tokptr], (strptr+1)*sizeof(char));
            (*tokens)[tokptr][strptr] = 0;
            tokptr++;
            (*tokens) = realloc((*tokens), (tokptr+1)*sizeof(char*));
            (*tokens)[tokptr] = NULL;
            strptr = 0;
        } else {
            (*tokens)[tokptr] = realloc((*tokens)[tokptr], (strptr+1)*sizeof(char));
            (*tokens)[tokptr][strptr] = string[ptr];
            strptr++;
        }
        ptr++;
    }
    (*tokens)[tokptr] = realloc((*tokens)[tokptr], (strptr+1)*sizeof(char));
    (*tokens)[tokptr][strptr] = 0;
    return ++tokptr;
}

bool my_strcmp(char *string1, char *string2) {
    int ptr = 0;
    while (string1[ptr] != 0 || string2[ptr] != 0) {
        if (string1[ptr] != string2[ptr]) {
            return false;
        }
        ptr++;
    }
    return true;
}

int main() {
    char **tokens = NULL;
    char string1[] = "Hello World!";
    char string2[] = "Hello World!";
    int tokenCount = my_strtok(&tokens, string1, ' ');
    
    for (int i = 0; i < tokenCount; i++) {
        printf("%s\n", tokens[i]);
    }

    printf("%d\n", my_strcmp(string1, string2));

    for (int i = 0; i < tokenCount; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}