#include "../includes/minishell.h"

//inicia variaveis do programa
char **copy_envp(char **envp)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = 0;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs);
    while (i < amount_strs)
    {
        cpy_envp[i] = ft_strdup(envp[i]);
        i++;
    }
    return (cpy_envp);
}

int init_vars(t_data *minishell, char **envp) // adicionei o envp como parâmetro
{
    char buff[4097];
    char *home;

    home = getenv("HOME"); //recupera uma variavel env
    getcwd(buff, 4096); // pega o caminho atual
    if(ft_memcmp(buff, home, ft_strlen(home)))
        minishell->cwd_path = ft_strdup(buff);
    else
        minishell->cwd_path = ft_strjoin("~", buff + ft_strlen(home));
    minishell->readline = NULL;
    minishell->cmd_split = NULL;
    minishell->minishell_envp = copy_envp(envp); // inicialização da nossa envp
    return(0);
}

int init_readline(t_data *minishell)
{
    while (1)
    {
        minishell->readline = readline("minishell~> ");
        add_history(minishell->readline);

       //minishell->cmd_split = split_quotes(minishell->readline, ' '); 
        //usar depois de tratar os espaços errados ^^^^
    }
}