#include "../.././includes/minishell.h"

int check_input(t_data *minishell)
{
	t_commands	*temp;

	temp = minishell->commands;
	while (temp != NULL)
	{
		if (temp->cmd[0] == '>' && temp->cmd[1] == '>')
			temp->token = APPEND_OUTPUT;
		else if (temp->cmd[0] == '>' && temp->cmd[1] == '\0')
			temp->token = REDIRECT_OUTPUT;
		else if (temp->cmd[0] == '<' && temp->cmd[1] == '\0')
			temp->token = REDIRECT_INPUT;
		else if (temp->cmd[0] == '<' && temp->cmd[1] == '<')
			temp->token = HEREDOC;
		else if (temp->cmd[0] == '|' && temp->cmd[1] == '\0')
			temp->token = PIPE;
		else
			temp->token = NORMAL_ARG;
		temp = temp->next;
	}
	return (SUCESS);
}

void create_list(t_data *minishell)
{
	int i;

	minishell->cmd_split = split_quotes(minishell->expanded_str, ' ');
    minishell->cmd_count = count_strs(minishell->cmd_split);
    i = -1;
    while (minishell->cmd_split[++i])
	{
        lstadd_back_command(&minishell->commands, lstnew_command(minishell->cmd_split[i]));
	}
	check_input(minishell);
}