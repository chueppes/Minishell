#include "../.././includes/minishell.h"
// C program to search and replace
// all occurrences of a word with
// other word.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to replace a string with another
// string
char* replaceWord(const char* s, const char* oldW,
				const char* newW)
{
	char* result;
	int i, cnt = 0;
	int newWlen = strlen(newW);
	int oldWlen = strlen(oldW);

	// Counting the number of times old word
	// occur in the string
	for (i = 0; s[i] != '\0'; i++) {
		if (strstr(&s[i], oldW) == &s[i]) {
			cnt++;

			// Jumping to index after the old word.
			i += oldWlen - 1;
		}
	}

	// Making new string of enough length
	result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);

	i = 0;
	while (*s) {
		// compare the substring with the result
		if (strstr(s, oldW) == s) {
			strcpy(&result[i], newW);
			i += newWlen;
			s += oldWlen;
		}
		else
			result[i++] = *s++;
	}

	result[i] = '\0';
	return result;
}



char *get_var_value(char *var, t_data *data)
{
    int i=0;
    int j=0;
    int size=0;
    char *word="NULL";
    while(data->minishell_envp[i])
    {
        if(ft_strnstr(data->minishell_envp[i], var, ft_strlen(data->minishell_envp[i])))
        {
            j = j + ft_strlen(var) + 1;
            size=j;
            while(data->minishell_envp[i][size] != '\0')
                size++;
            word = malloc(size);
            int k=0;
            while(data->minishell_envp[i][j] != '\0')
                {
                    word[k]=data->minishell_envp[i][j];
                    k++;
                    j++;
                }
                word[k] = '\0';
            return(word);
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
    // char *str="NULL";
    char *var="NULL";
    int count=1;
    int k=0;
    while(data->cmd_split[i])
    {
        if(ft_strchr(data->cmd_split[i], '$'))
            {
                while(data->cmd_split[i][count] != '$' && data->cmd_split[i][count] != '\0')
                     count++;
                var = malloc(count-1);
                count=1;
                while(data->cmd_split[i][count] != '$' && data->cmd_split[i][count] != '\0')
                    {
                        var[k] = data->cmd_split[i][count];
                        k++;
                        count++;
                    }
                var[k] = '\0';
                printf("value: %s\n", var);
                if(ft_isalpha(var[j]))
                { 
                    // str=malloc(ft_strlen(data->cmd_split[i]));
                    // ft_strlcpy(str, ft_strtrim(data->cmd_split[i], "$"), ft_strlen(data->cmd_split[i]));
                    // printf("trim :%s\n", str);
                    ft_strlcpy(data->cmd_split[i], ft_strtrim(data->cmd_split[i], "$"), ft_strlen(ft_strtrim(data->cmd_split[i], "$")));
                    ft_strlcpy(data->cmd_split[i],  get_var_value(var, data), ft_strlen(get_var_value(var, data))+1);
                    // printf("replace :%s\n", replaceWord(data->cmd_split[i], var, get_var_value(var, data)));
                    printf("%s\n", data->cmd_split[i]);
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
  