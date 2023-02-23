#include "../.././includes/minishell.h"

int	ft_strchars_i(const char *s, char *set)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	should_var_be_expanded(char *str, int i, int sq_open, int dq_open)
{
	int	found_forbidden_char_after_dollar;
	int	not_has_dq_case_trated;
	int	has_dq_case_trated;

	if (sq_open || str[i] != '$' || !str[i + 1])
		return (0);
	found_forbidden_char_after_dollar = ft_strchars_i(str + i + 1, "/~%^{}:;");
	if (found_forbidden_char_after_dollar == 0)
		return (0);
	not_has_dq_case_trated = (ft_strchars_i(str + i + 1, " ") && !dq_open);
	has_dq_case_trated = (ft_strchars_i(str + i + 1, "\"") && dq_open);
	return (not_has_dq_case_trated || has_dq_case_trated);
}

char	*expansion(char *str, t_data *data)
{
	int	sq_open;
	int	dq_open;
	int	i;

	sq_open = 0;
	dq_open = 0;
	i = 0;
	while (str && str[i])
	{
		sq_open = (sq_open + (!dq_open && str[i] == 39)) % 2;
		dq_open = (dq_open + (!sq_open && str[i] == '"')) % 2;
		if (should_var_be_expanded(str, i, sq_open, dq_open))
			return (expansion(expand_vars(str), data));
		i++;
	}
	return (str);
}

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
