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
    char    *expanded_str;
    char **envp;
    t_commands commands;
}           t_data;

int     init_vars(t_data *minishell, char **envp); // adicionado envp como parametro
int     init_readline(t_data *minishell);
char	**split_quotes(char const *s, char c);
int     count_strs(char **strs);
int     is_space(int c);
int     is_special_char(char *str);
char    *separate_by_spaces(char *str);
int parsing(t_data *minishell);
int ft_strsearch(const char *str, char *comp);
int is_builtin(t_data *minishell);
void     exec_env(t_data *data);
char* expand_vars(char* string);
char	*expansion(char *str, t_data *data);

#endif