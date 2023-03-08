#include "../.././includes/minishell.h"

int is_readline_valid(char *readline);
int get_value_out(char *readline);

int treat_input(t_data *minishell)
{
   
    if(!check_quotes(minishell->readline))
        return(handle_errors(QUOTE_ERR, 1, NULL)); 
    add_history(minishell->readline);
    minishell->expanded_str = separate_by_spaces(minishell->readline);
    minishell->cmd_split = split_quotes(minishell->expanded_str, ' ');
    if (start_expansions(minishell->cmd_split, minishell))
        return(1);
    return(0);
}