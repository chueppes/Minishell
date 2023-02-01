#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_data minishell;

    (void)argv;
    (void)envp;
    if(argc != 1)
        return(1);
    init_vars(&minishell, envp);
     //adicionado envp como parametro
    init_readline(&minishell);
    is_builtin(&minishell);
}
