#include "../.././includes/minishell.h"

void	start_expansions(char **commands, t_data *data)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		commands[i] = expand_vars(commands[i], data);
		commands[i] = expand_path(commands[i], data);
		printf("%s\n", commands[i]);
		i++;
	}
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