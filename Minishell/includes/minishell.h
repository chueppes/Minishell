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
    char                **exec_cmd;
    char                *cmd_path;
    struct s_commands   *next;
}                       t_commands;

typedef struct s_data {
    char        *readline;
    char        *cwd_path;
    char        *home;  
    char        **cmd_split;
    char        **minishell_envp;
    char        *expanded_str;
    int         cmd_count;
    t_commands  *commands;
}               t_data;

enum    input_type {
    REDIRECT_INPUT = 1000,

};

// init readline
int         init_vars(t_data *minishell, char **envp);
int         init_readline(t_data *minishell);

// utils
int         count_strs(char **strs);
int         is_space(int c);
int         is_special_char(char *str);

// treatment
char        **split_quotes(char const *s, char c);
char        *separate_by_spaces(char *str);

// list
void        lstadd_back_command(t_commands **lst, t_commands *new_lst);
t_commands	*lstnew_command(char *content);
void        split_list(t_commands **command);

// path
char        *create_path(char **paths, char *cmd);
char        *find_path(char *cmd, char **envp);

// free_all
void        free_list(t_commands **list);
void        free_all(t_data *minishell);

// parser
int         check_input(t_data *minishell);

#endif