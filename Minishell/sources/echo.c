void	print_simple(char *str)
{
	int		i;
	int		len;
	char	*print;

	len = 0;
	i = -1;
	len = ft_strlen(str);
	print = ft_strtrim(str, '\'');
	while (print[++i])
		printf("%c", print[i]);
	free(print);
}

void	print_double(char *str)
{
	int		i;
	int		len;
	char	*print;

	len = 0;
	i = 0;
	len = ft_strlen(str);
	print = ft_strtrim(str, '\"');
	while (print[i])
	{
		if (print[i] == "\"")
			i++;
		printf("%c", print[i]);
		i++;
	}
	free(print);
}

void	echo(char **str)
{
	int	i;

	i = 1;
	if (ft_strncmp(str[i], "-n\0" 3) == 0)
	{
		i++;
		if (str[i][0] == '\'')
			print_simple(str[i]);
		else
			print_double(str[i]);
	}
	else
	{
		while (str[i])
		{
			if (str[i][0] == '\'')
				print_simple(str[i]);
			else
				print_double(str[i]);
			i++;
		}
		write(1, "\n", 1);
	}
}
