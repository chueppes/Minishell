#include "../.././includes/minishell.h"

int is_readline_valid(char *readline);
int get_value_out(char *readline);

int treat_input(t_data *minishell)
{
    // if(is_readline_valid(minishell->readline))
    //      return(get_value_out(minishell->readline));
    add_history(minishell->readline);
    minishell->expanded_str = separate_by_spaces(minishell->readline);
    minishell->cmd_split = split_quotes(minishell->expanded_str, ' ');
    start_expansions(minishell->cmd_split, minishell);
    return(1);
}

int is_null(char *readline)
{
    return(readline == NULL);
}

int is_empty(char *readline)
{
    return(readline && ft_strlen(readline) == 0);
}

int get_value_out(char *readline)
{
    if(is_null(readline))
        return (0);
    return(1);
}

int is_readline_valid(char *readline)
{
    return(is_empty(readline) || is_null(readline));
}