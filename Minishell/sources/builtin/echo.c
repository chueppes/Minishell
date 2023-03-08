#include "../../includes/minishell.h"

void	print_space(char **str, int i)
{
	if (str[i + 1])
		printf(" ");
}

void	print_echo(char *str, int type)
{
	int		i;
	char	*print;

	if (type == 1)
	{
		i = -1;
		print = ft_strtrim(str, "\'");
		while (print[++i])
			printf("%c", print[i]);
	}
	else
	{
		i = 0;
		print = ft_strtrim(str, "\"");
		while (print[i])
		{
			if (print[i] == '\"')
				i++;
			printf("%c", print[i]);
			i++;
		}
	}
	free(print);
}

void	chose_echo(char **str, int flag, int i)
{
	if (flag == 0)
	{
		while (str[i])
		{
			if (str[i][0] == '\'')
				print_echo(str[i], 1);
			else
				print_echo(str[i], 2);
			print_space(str, i);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (str[i][0] == '\'')
				print_echo(str[i], 1);
			else
				print_echo(str[i], 2);
			print_space(str, i);
			i++;
		}
		printf("\n");
	}
}

int	flag_check(char *str)
{
	int	i;

	i = 1;
	while (str[i] == 'n' && str[i])
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

void	do_echo(char **str)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (ft_strcmp(str[i], "-n") == 0 || flag_check(str[i]) == 0)
	{
		flag = 0;
		i++;
	}
	chose_echo(str, flag, i);
}
