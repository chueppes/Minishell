#include "../.././includes/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_quotes(char* string) 
{
    int inside_quotes = 0;
    int inside_single_quotes = 0;
    const char* p = string;
    while (*p) 
    {
        if (*p == '"' && !inside_single_quotes)
            inside_quotes = !inside_quotes;
        else if (*p == '\'' && !inside_quotes)
            inside_single_quotes = !inside_single_quotes;
        else if (!inside_quotes && !inside_single_quotes && (*p == '"' || *p == '\''))
            return (0);
        p++;
    }
    if (inside_quotes || inside_single_quotes) 
        return (0);
    return (1);
}

char* remove_outer_quotes(char* string)
 {
    char* result = NULL;
    int len = strlen(string);
    int i = 0;
    char* trimmed = NULL;
    char quote[2] = {0}; // inicializa quote como uma string vazia
    while (i < len) {// procura a primeira aspa
        if (string[i] == '"' || string[i] == '\'') {
            quote[0] = string[i];
            break;
        }
        i++;
    }
    if (quote[0] == '\0') // se não encontrar aspas, retorna a string original
    {
        result = (char*) malloc(sizeof(char) * (len + 1));
        ft_strcpy(result, string);
        free(string);
        return result;
    }
    trimmed = ft_strtrim(string, quote);// remove todas as ocorrências da primeira aspa encontrada
    len = ft_strlen(trimmed);
    result = (char*) malloc(sizeof(char) * (len + 1));
    int j = 0;
    i=-1;
    while ( ++i < len) // copia o resultado para a string final
    {
        if (trimmed[i] != quote[0]) 
            result[j++] = trimmed[i];
    }
    result[j] = '\0';
    free(trimmed); // libera a memória alocada por ft_strtrim
    free(string);
    return result;
}
