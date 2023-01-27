#ifndef LIST_H
# define LIST_H

typedef struct s_commands
{
    char                *cmd;
    char                *cmd_path;
    struct s_commands   *next;
}           t_commands;

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	lstadd_back_command(t_commands **lst, t_commands *new);
t_commands	*lstlast_command(t_commands *lst);
t_commands	*lstnew_command(void *content);
int create_list(t_data *minishell);

#endif