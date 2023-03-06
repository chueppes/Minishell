#include "../.././includes/minishell.h"

int is_readline_valid(char *readline);
int get_value_out(char *readline);

int treat_input(t_data *minishell)
{
    add_history(minishell->readline);
    minishell->expanded_str = separate_by_spaces(minishell->readline);
    minishell->cmd_split = split_quotes(minishell->expanded_str, ' ');
    start_expansions(minishell->cmd_split, minishell);
    return(1);
}