#include ".././includes/minishell.h"

char	*create_path(char **paths, char *cmd)
{
	int		j;
	char	*final_path;
	char	*temp;

	j = 0;
	while (paths[j])
	{
		temp = ft_strjoin(paths[j], "/");
		final_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(final_path, F_OK | X_OK) == 0)
			return (final_path);
		else
			j++;
	}
	return (final_path);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*final_path;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			final_path = create_path(paths, cmd);
		}
		i++;
	}
	if (access(final_path, F_OK | X_OK) == -1)
    {
		handle_errors(CMDNOTFOUND_ERR, 0, cmd);
		exit(-1);
		return (NULL);
    }
	// virar um outro return de existe;
	return (final_path);
}