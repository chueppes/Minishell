#ifndef MINISHELL_H
# define MINISHELL_H

# include "../sources/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>

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
    t_commands commands;
}           t_data;

int     init_vars(t_data *minishell, char **envp); // adicionado envp como parametro
int     init_readline(t_data *minishell);
char    **split_quotes(char *str, char c);
int     count_strs(char **strs);

#endif