#include "../../includes/minishell.h"

char	*remove_tilda(char *path)
{
	char	*rest_path;
	int		i;

	i = -1;
	rest_path = malloc(ft_strlen(path) - 2);
	while(path[++i])
		rest_path[i] = path[i + 2];
	return (rest_path);
}

char	*treat_home(char **env)
{
	int		home_local;
	char	*exec_home;
	int 	i;
	int 	j;

	home_local = 0;
	i = 5;
	j = 0;
	while (ft_strncmp(env[home_local], "HOME=", 5) != 0)
		home_local++;
	exec_home = malloc(ft_strlen(env[home_local]) - 4);
	while(env[home_local][i])
	{
		exec_home[j] = env[home_local][i];
		j++;
		i++;
	}
	exec_home[j + 1] = '\0';
	return (exec_home);
}

void	do_cd(char *path, char **env, t_data *mini)
{
	char	*exec_home;
	char	*temp_pwd;

	if (ft_strcmp(path, "-") == 0)
	{
		temp_pwd = getcwd(NULL, 0);
		chdir(mini->old_pwd);
        printf("%s\n", mini->old_pwd);
        mini->old_pwd = temp_pwd;
        free(temp_pwd);
	}
    else if (ft_strcmp(path, "~") == 0 || ft_strcmp(path, "~/") == 0)
	{
		exec_home = treat_home(env);
		chdir(exec_home);
		free(exec_home);
	}
	else if (ft_strncmp(path, "~/", 2) == 0)
	{
		exec_home = ft_strjoin(treat_home(env), remove_tilda(path));
		chdir(exec_home);
		free(exec_home);
	}
    else if (chdir(path) == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", path);
	 	return ;
	}
}
