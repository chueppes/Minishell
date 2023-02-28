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
    int                 token;
    struct s_commands   *next;
}                       t_commands;

typedef struct s_exec
{
	char				*aux;
	char                **exec_cmd;
	int                 infile;
    int                 outfile;
	struct s_exec  *next;
}						t_exec;

typedef struct s_data {
    char        *readline;
    char        *cwd_path;
    char        *home;  
    char        **cmd_split;
    char        **minishell_envp;
    char        *expanded_str;
    char        *old_pwd;
    t_commands  *commands;
	t_exec		*exec_list;
}               t_data;

enum    input_type {
	REDIRECT_INPUT = 1000,
	REDIRECT_OUTPUT = 1001,
	APPEND_OUTPUT = 1002,
	HEREDOC = 1003,	
	PIPE = 1006,
	NORMAL_ARG = 1007,
    FILE_NAME = 1008,
    DELIMITER = 1009,
};

#define SUCESS 0
#define FAILURE -1

// init readline
int         init_vars(t_data *minishell, char **envp);
int         init_readline(t_data *minishell);

// utils
int         count_strs(char **str);
int         ft_strcmp(const char *s1, const char *s2);

// treatment
char        **split_quotes(char const *s, char c);
char        *separate_by_spaces(char *str);
int         check_quotes(char* string);
char*       remove_outer_quotes(char* string);

// list
void        lstadd_back_command(t_commands **lst, t_commands *new_lst);
t_commands	*lstnew_command(char *content);
void		lstadd_back_exec(t_exec **lst, t_exec *new_lst);
t_exec		*lstnew_exec(char *content);

// path
char        *create_path(char **paths, char *cmd);
char        *find_path(char *cmd, char **envp);

// free_all
void        free_list_comm(t_commands **list);
void        free_list_exec(t_exec **list);
void        free_all(t_data *minishell);

// parser
//int         parse_error(t_data *minishell);
int         parser(t_data *minishell);
int         check_input(t_data *minishell);
int         check_input2(t_data *minishell);
void		create_exec_list(t_exec **exec_com, t_commands *comm);
int			search_redirect(t_commands **comm, t_exec **exec_list);
int			find_position_open(t_commands *comm, int i);
int			check_executable(t_commands *check_exec);

//utils_open
int			open_output(t_commands **comm, t_exec **exec_list, int i, char *file);
int         open_append(t_commands **comm, t_exec **exec_list, int i, char *file);
int         open_input(t_commands **comm, t_exec **exec_list, int i, char *file);

// execution
void        prepare_for_execution(t_exec **exec_list);
void		ft_pipe(t_data *mini, int *prevpipe, t_exec *exec_list);
void		ft_last_prog(t_data *mini, int prevpipe, t_exec *exec_list);
int 		execute_pipes(t_data *minishell);

//expansions
void	start_expansions(char **commands, t_data *data);
char	*expand_path(char *str, t_data *data);
char	*expand_vars(char *str, t_data *data);
int	    ft_strnchar(const char *s, char *set);
char	*ft_getenv(char *key, char **envp, int key_size);

// builtin
void	do_cd(char *path, char **env, t_data *mini, int empity);
void    do_export(char **envp, char *str, t_data *mini);
void    do_unset(char **env, char *unset, t_data *mini);
void	do_echo(char **str);
void    do_env(t_data *envp);
void    do_pwd(void);


#endif