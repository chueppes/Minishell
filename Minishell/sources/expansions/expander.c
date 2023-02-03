#include "../.././includes/minishell.h"

char *get_var_value(char *var, t_data *data)
{
    int i=0;
    int j=0;
    while(data->minishell_envp[i])
    {
        if(ft_strnstr(data->minishell_envp[i], var, ft_strlen(data->minishell_envp[i])))
        {
            j = j + ft_strlen(var) + 1;
            while(data->minishell_envp[i][j] != '\0')
                printf("%c", data->minishell_envp[i][j++]);
        }
        i++;
    }
    return("null");
}

char *expand(t_data *data)
{
    int i=0;
    int j=1;
    // int count=0;
    char *str="NULL";
    while(data->cmd_split[i])
    {
        if(ft_strchr(data->cmd_split[i], '$'))
            {
                if(ft_isalpha(data->cmd_split[i][j]))
                { 
                    str=malloc(ft_strlen(data->cmd_split[i]));
                    ft_strlcpy(str, ft_strtrim(data->cmd_split[i], "$"), ft_strlen(data->cmd_split[i]));
                    printf("%s\n", str);
                    get_var_value(str, data);
                }
                else if(data->cmd_split[i][j] == '?')
                    printf("%s\n", "global");
            }
        else
            return("ERROR");
        i++;
    }   
    return(0);
}
  