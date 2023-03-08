#include "../../includes/minishell.h"

char	**modify_env(char **envp, char *str, int j)
{
	char	**cpy_envp;
	int		amount_strs;
	int		i;

	i = -1;
	amount_strs = count_strs(envp);
	cpy_envp = (char **)malloc(sizeof(char *) * amount_strs + 1);
	while (++i < amount_strs && ft_strncmp(envp[i], str, j) != 0)
		cpy_envp[i] = ft_strdup(envp[i]);
	cpy_envp[i] = ft_strdup(str);
	while (++i < amount_strs)
		cpy_envp[i] = ft_strdup(envp[i]);
	cpy_envp[i] = NULL;
	return (cpy_envp);
}

char	**add_env(char **envp, char *str)
{
	char	**cpy_envp;
	int		amount_strs;
	int		i;

	i = -1;
	amount_strs = count_strs(envp);
	cpy_envp = (char **)malloc(sizeof(char *) * amount_strs + 1);
	while (++i < amount_strs)
		cpy_envp[i] = ft_strdup(envp[i]);
	cpy_envp[i] = ft_strdup(str);
	cpy_envp[i + 1] = NULL;
	return (cpy_envp);
}

void	do_export(char **envp, char *str, t_data *mini)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!str)
	{
		do_env(mini, 0);
		return ;
	}
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '\0')
		return ;
	while (envp[++j])
	{
		if (ft_strncmp(envp[j], str, i) == 0)
		{
			mini->minishell_envp = modify_env(envp, str, i);
			return ;
		}
	}
	mini->minishell_envp = add_env(envp, str);
}
