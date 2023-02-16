#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*remove_tilda(char *path)
{
	char	*rest_path;
	int		i;

	i = -1;
	rest_path = malloc(strlen(path) - 2);
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
	while (strncmp(env[home_local], "HOME=", 5) != 0)
		home_local++;
	exec_home = malloc(strlen(env[home_local]) - 4);
	while(env[home_local][i])
	{
		exec_home[j] = env[home_local][i];
		j++;
		i++;
	}
	exec_home[j + 1] = '\0';
	return (exec_home);
}

void	do_cd(char *path, char **env)
{
	char	*exec_home;
	char	*temp_pwd;
	char	*old_pwd; //colocar dentro da struct

	if (strcmp(path, "-") == 0)
	{
		temp_pwd = getcwd(NULL, 0);
		chdir(old_pwd);
        printf("%s\n", old_pwd);
        old_pwd = temp_pwd;
        free(temp_pwd);
	}
    else if (strcmp(path, "~") == 0 || strcmp(path, "~/") == 0)
	{
		exec_home = treat_home(env);
		chdir(exec_home);
		printf("%s\n", getcwd(NULL, 0));
	}
	else if (strncmp(path, "~/", 2) == 0)
	{
		// exec_home = ft_strjoin(treat_home(env), remove_tilda(path));
		chdir(exec_home);
	}
    else if (chdir(path) == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", path);
	 	return ;
	}
	else
	 	chdir(path);
}

int	main(int argc, char **argv, char **envp)
{
	do_cd("~", envp);
	return (0);
}