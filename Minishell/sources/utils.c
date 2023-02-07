#include ".././includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t          i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (*str1 - *str2);
	while (i <= ft_strlen(s1) && i <= ft_strlen(s2))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int  count_pipes(t_commands *comm)
{
    int i;

    i = 0;
    while (comm != NULL)
	{
		if (comm->cmd[0] == '|')
			i++;
		comm = comm->next;
	}
    return (i);
}

int  count_strs(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void do_trim(char ***cmd) // tem que mudar para receber lista ao invés de 3 ponteiros
{
	int		i;
//	int		len;
//	char	*aux;
	char	**tmp;

	tmp = *cmd;
	i = 0;
	while (tmp[i])
	{
		if (ft_strchr(tmp[i], '\"') && ft_strrchr(tmp[i], '\"'))
			tmp[i] = ft_strtrim(tmp[i], "\"");
		if (ft_strchr(tmp[i], '\'') && ft_strrchr(tmp[i], '\''))
			tmp[i] = ft_strtrim(tmp[i], "\'");
		i++;
	}
}

