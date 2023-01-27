#ifndef LIST_H
# define LIST_H

typedef struct s_commands
{
    char                *cmd;
    char                *cmd_path;
    struct s_commands   *next;
}           t_commands;

typedef struct s_data {
    char    *readline;
    char    *cwd_path;
    char    *home;  
    char    **cmd_split;
    char    **minishell_envp;
    int     cmd_count;
    char    *expanded_str;
    t_commands commands;
}           t_data;

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft.h"

void	lstadd_back_command(t_commands **lst, t_commands *new_lst);
t_commands	*lstlast_command(t_commands *lst);
t_commands	*lstnew_command(void *content);
int create_list(t_data *minishell);

#endif