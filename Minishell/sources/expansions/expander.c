#include "../.././includes/minishell.h"

char* expand_vars(char* string) {
    char* buffer = malloc(sizeof(char));
    if (buffer == NULL) {
        return NULL; // Falha na alocação de memória
    }
    int buffer_pos = 0;
    int string_pos = 0;
    while (string[string_pos] != '\0') {
        if (string[string_pos] == '$' && string[string_pos+1] != '\0') {
            // Encontrou uma variável
            int var_start_pos = string_pos + 1;
            int var_end_pos = var_start_pos;
            while (string[var_end_pos] != '\0' && ((string[var_end_pos] >= '0' && string[var_end_pos] <= '9') || (string[var_end_pos] >= 'A' && string[var_end_pos] <= 'Z') || (string[var_end_pos] >= 'a' && string[var_end_pos] <= 'z') || string[var_end_pos] == '_')) {
                var_end_pos++;
            }
            char* var_name = malloc(sizeof(char) * (var_end_pos - var_start_pos + 1));
            if (var_name == NULL) {
                free(buffer); // Liberar memória alocada anteriormente
                return NULL; // Falha na alocação de memória
            }
            strncpy(var_name, &string[var_start_pos], var_end_pos - var_start_pos);
            var_name[var_end_pos - var_start_pos] = '\0';
            char* var_value = getenv(var_name);
            free(var_name); // Liberar memória alocada para var_name
            if (var_value != NULL) {
                int var_value_len = strlen(var_value);
                char* new_buffer = realloc(buffer, sizeof(char) * (buffer_pos + var_value_len + 1));
                if (new_buffer == NULL) {
                    free(buffer); // Liberar memória alocada anteriormente
                    return NULL; // Falha na alocação de memória
                }
                buffer = new_buffer;
                strncpy(&buffer[buffer_pos], var_value, var_value_len);
                buffer_pos += var_value_len;
            }
            string_pos = var_end_pos;
        } else {
            buffer[buffer_pos] = string[string_pos];
            buffer_pos++;
            string_pos++;
        }
    }
    buffer[buffer_pos] = '\0';
	strcpy(string, buffer);
    free(buffer); // Liberar memória alocada para buffer
    return string;
}
