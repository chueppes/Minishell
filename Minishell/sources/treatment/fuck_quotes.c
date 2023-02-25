#include "../.././includes/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_quotes(char* string) {
    int inside_quotes = 0, inside_single_quotes = 0;
    for (char* p = string; *p; p++) {
        if (*p == '"' && !inside_single_quotes) inside_quotes = !inside_quotes;
        else if (*p == '\'' && !inside_quotes) inside_single_quotes = !inside_single_quotes;
        else if (!inside_quotes && !inside_single_quotes && (*p == '"' || *p == '\'')) {
            fprintf(stderr, "Erro: aspas abertas\n");
            return 1;
        }
    }
    if (inside_quotes || inside_single_quotes) {
        fprintf(stderr, "Erro: aspas não fechadas\n");
        return 1;
    }
    return 0;
}

char* remove_outer_quotes(char* string) {
    int len = strlen(string);
    int start = 0, end = len - 1;

    while (isspace(string[start])) start++; // remove espaços no início
    while (isspace(string[end])) end--; // remove espaços no final

    if (string[start] == '"' && string[end] == '"' && start < end) { // remove aspas duplas
        start++;
        end--;
    }
    else if (string[start] == '\'' && string[end] == '\'' && start < end) { // remove aspas simples
        start++;
        end--;
    }

    char* result = (char*) malloc(sizeof(char) * (end - start + 2));
    strncpy(result, &string[start], end - start + 1);
    result[end - start + 1] = '\0';

    return result;
}
