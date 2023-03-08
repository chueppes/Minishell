#include "../../includes/minishell.h"

void	print_space(char **str, int i)
{
	if (str[i + 1])
		printf(" ");
}

void	print_simple(char *str)
{
	int		i;
	char	*print;

	i = -1;
	print = ft_strtrim(str, "\'");
	while (print[++i])
		printf("%c", print[i]);
	free(print);
}

void	print_double(char *str)
{
	int		i;
	char	*print;

	i = 0;
	print = ft_strtrim(str, "\"");
	while (print[i])
	{
		if (print[i] == '\"')
			i++;
		printf("%c", print[i]);
		i++;
	}
	free(print);
}

void	chose_echo(char **str, int flag, int i)
{
	if (str[i + 1] && flag == 0)
	{
		while (str[i])
		{
			if (str[i][0] == '\'')
				print_simple(str[i]);
			else
				print_double(str[i]);
			print_space(str, i);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (str[i][0] == '\'')
				print_simple(str[i]);
			else
				print_double(str[i]);
			print_space(str, i);
			i++;
		}
		printf("\n");
	}
}

void	do_echo(char **str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (ft_strcmp(str[++i], "-n") == 0)
		flag = ft_strcmp(str[i], "-n");
	chose_echo(str, flag, i);
}
