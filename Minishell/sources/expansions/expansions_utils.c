#include "../.././includes/minishell.h"

//static int get_key_size(char *commands);

int	start_expansions(char **commands, t_data *data)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		check_quotes(commands[i]);
		write(1, "oioi", 5);
		commands[i] = expand_vars(commands[i], data);
		write(1, "tchau", 6);
		commands[i] = expand_path(commands[i], data);
		remove_outer_quotes(commands[i]);
		i++;
	}
	return(1);
}

int	ft_strnchar(const char *s, char *set)
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

char	*ft_getenv(char *key, char **envp, int key_size)
{
   
	int	i;

	i = 0;
	if (key_size < 0)
		key_size = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], key_size) == 0 && envp[i][key_size] == '=')
			return (ft_strdup(envp[i] + key_size + 1));
		i++;
	}

	return (NULL);
}

/*static int get_key_size(char *commands)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while ((commands[i] == '\'' || commands[i] == '\"') && commands[i] != 0)
		i++;
	if (commands[i] == '$')
	{
		while (commands[i] && commands[i] != '\'' && commands[i] != '\"')
		{
			i++;
			count++;
		}
	}
	return (count);
}*/