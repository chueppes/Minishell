#include "../../includes/minishell.h"

int	flag_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == 'n')
		i++;
	if (i == 1)
		while (str[i] == 'n' && str[i])
			i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

void	print_echo(char *str, int type)
{
	int		i;
	char	*print;

	i = -1;
	if (type == 1)
		print = ft_strtrim(str, "\'");
	else
		print = ft_strtrim(str, "\"");
	while (print[++i])
	{
		if (type != 1)
			while (print[i] == '\"')
				i++;
		printf("%c", print[i]);
	}
	free(print);
}

void	do_echo(char **str)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (str[i] && (ft_strcmp(str[i], "-n") == 0 || flag_check(str[i]) == 0))
	{
		flag = 0;
		i++;
	}
	while (str[i])
	{
		if (str[i][0] == '\'')
			print_echo(str[i], 1);
		else
			print_echo(str[i], 2);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	if (flag == 1)
		printf("\n");
}
