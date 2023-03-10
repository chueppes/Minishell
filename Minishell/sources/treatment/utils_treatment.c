#include "../.././includes/minishell.h"

void	ft_check_syntax_aux_1(char *str, int *start, int *i, char *copy)
{
	if (str[*start] == '"')
	{
		copy[*i] = str[*start];
		*i = *i + 1;
		*start = *start + 1;
		while (str[*start] != '"' && str[*start])
		{
			copy[*i] = str[*start];
			*i = *i + 1;
			*start = *start + 1;
		}
	}
	else if (str[*start] == 39)
	{
		copy[*i] = str[*start];
		*i = *i + 1;
		*start = *start + 1;
		while (str[*start] != 39 && str[*start])
		{
			copy[*i] = str[*start];
			*i = *i + 1;
			*start = *start + 1;
		}
	}
}

int	ft_check_syntax_aux_0(char *str, int *start, int *i, char *copy, int *j)
{
	if (str[*j] == '|')
	{
		free(copy);
		return (1);
	}
	ft_check_syntax_aux_1(str, start, i, copy);
	copy[*i] = str[*start];
	if (is_special_char(&str[*j]) == 2)
		*j = *j + 1;
	if (multi(str, *start) == 1)
	{
		*i = *i + 1;
		copy[*i] = ' ';
	}
	return (0);
}