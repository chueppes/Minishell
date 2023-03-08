#include "../../includes/minishell.h"

char	**unset_env(char **envp, int unset_i)
{
	char	**cpy_envp;
	int		amount_strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	amount_strs = count_strs(envp);
	cpy_envp = (char **)malloc(sizeof(char *) * amount_strs);
	while (i < amount_strs && i != unset_i)
	{
		cpy_envp[j] = ft_strdup(envp[i]);
		i++;
		j++;
	}
	i++;
	while (i < amount_strs)
	{
		cpy_envp[j] = ft_strdup(envp[i]);
		j++;
		i++;
	}
	cpy_envp[j] = NULL;
	return (cpy_envp);
}

void	do_unset(char **env, char *unset, t_data *mini)
{
	int	i;
	int	len_unset;

	i = -1;
	len_unset = ft_strlen(unset);
	while (env[++i])
	{
		if (ft_strncmp(unset, env[i], len_unset) == 0)
			mini->minishell_envp = unset_env(env, i);
	}
}
