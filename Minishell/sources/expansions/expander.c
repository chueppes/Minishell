#include "../.././includes/minishell.h"

char *expand(t_data *data)
{
    int i=0;
    int size=0;
    while(data->cmd_split[i])
    {
        if (data->cmd_split[i] == "$")
         {
            while(data->cmd_split[i] != "$")
            {
                size++;
                i++;
            } 
         }   
    while(data->minishell_envp)
}