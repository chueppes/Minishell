#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_data minishell;

    (void)argv;
    (void)envp;
    if(argc != 1)
        return(handle_errors(0, 1, "The program should have at least one argument."));
    init_vars(&minishell, envp); //adicionado envp como parametro
    init_readline(&minishell);
}
