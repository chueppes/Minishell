#include "../.././includes/minishell.h"

void put_error(char *error)
{
    ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m", 2);
}

int handle_errors(int type_error, int code_error, char *output)
{
    global = code_error;
    if(type_error == FORK_ERR)
        put_error("Error at ./Minishell: Fork Failed."); // ok
    if(type_error == QUOTE_ERR)
        put_error("Error at ./Minishell: Did not found matching quote."); // ok
    if(type_error == PIPERR_ERR)
        put_error("Error at ./Minishell: Was not able to create pipe."); // fazendo
    if(type_error == OPENFILE_ERR)
        put_error("Error at ./Minishell: Syntax error near unexpected token 'newline'."); // ok
    if(type_error == PIPENDE_ERR)
        put_error("Error at ./Minishell: Syntax error near unexpected token '|'."); // ok
    if(type_error == NDIR_ERR)
        put_error("Error at ./Minishell: No such file or directory "); // ok
    if(type_error == NPERM_ERR)
        put_error("Error at ./Minishell: Permission denied.");
    if(type_error == ISDIR_ERR)
        put_error("Error at ./Minishell: Is a directory ");
    if(type_error == DUP_ERR)
        put_error("Error at ./Minishell: Dup2 Failed.");
    if(type_error == CMDNOTFOUND_ERR)
        put_error("Error at ./Minishell Command not found: "); // ok
    put_error(output);
    ft_putstr_fd("\n", 2);
    return(1);
}