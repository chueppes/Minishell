#include "../.././includes/minishell.h"

int	multi(char *str, int index)
{
	if (is_special_char(&str[index]) == 1 && !(is_space(str[index + 1])))
		return (1);
	if (!is_space(str[index]) && !is_special_char(&str[index])
		&& (is_special_char(&str[index + 1]) == 1))
		return (1);
	if (is_special_char(&str[index + 1]) == 2 && !is_space(str[index + 1]))
		return (1);
	return (0);
}

char	*check_syntax(char *str, int start, int end, char *copy)
{
	int	i;

	i = 0;
	while (str[start] && start <= end)
	{
		if (str[i] == '|')
		{
			free(copy);
			return ("ERROR: syntax error near unexpected token '|'");
		}
		if (str[start] == '"')
		{
			copy[i++] = str[start++];
			while (str[start] != '"' && str[start])
				copy[i++] = str[start++];
		}
        if (str[start] == 39)
		{
			copy[i++] = str[start++];
			while (str[start] != 39 && str[start])
				copy[i++] = str[start++];
		}
		copy[i] = str[start];
		if (is_special_char(&str[i]) == 2)
			i++;
		if (multi(str, start) == 1)
			copy[++i] = ' ';
		i++;
		start++;
	}
	copy[i] = '\0';
	return (copy);
}

int	is_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_special_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
	{
		if (str[i] == '>' && str[i + 1] == '>')
			return (2);
		else if (str[i] == '<' && str[i + 1] == '<')
			return (2);
		else if (str[i] == '|' && str[i + 1] == '|')
			return (2);
		else
			return (1);
	}
	return (0);
}

char	*separate_by_spaces(char *str)
{
	int		i;
	int		count;
	int		start;
	int		end;
	char	*copy;

	i = 0;
	count = 0;
	start = 0;
	while (is_space(str[i++]))
	start = i;
	while (str[i++])
	{
		if (is_special_char(&str[i]) == 2)
			i++;
		if (((is_special_char(&str[i]) == 1) && (!is_space(str[i + 1])))
			|| is_special_char(&str[i]) == 1)
			count++;
	}
	while (is_space(str[--i]))
		;
	end = i;
	copy = malloc(sizeof(char) * (end - start) + count + 1);
	return (check_syntax(str, start, end, copy));
}
