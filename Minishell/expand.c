#include <stdio.h>
#include <stdlib.h>

int is_space(int c)
{
     if(c == 32 || (c >= 9 && c <= 13))
        return(1);
    else
        return(0);
}

int is_special_char(char *str)
{
    int i=0;

    if(!str)
        return(0);
    if(str[i] == '>' || str[i] == '<' || str[i] == '|')
    {
        if(str[i] == '>' && str[i+1] == '>')
            return(2);
        else if (str[i] == '<' && str[i+1] == '<')
            return(2);
        else if (str[i] == '|' && str[i+1] == '|')
            return(2);
        else 
            return(1);
    }
    return(0);
}
char *separate_by_spaces(char *str)
{
    int i =0;
    int count=0;
    int start=0;
    int end = 0;
    int size = 0;
    char *copy;

    while (is_space(str[i]))
        i++;
    if (i>0)
        start = i-1;
    while (str[i])
    {
        if(is_special_char(&str[i]) == 2)
            i++;
        if(((is_special_char(&str[i])==1) && (!is_space(str[i+1]))) || ((!is_space(str[i])) && is_special_char(&str[i])==1))
            count++;
        i++;
    }
    while(is_space(str[--i]));
    end = i;
    size += end - start;
    copy = malloc(sizeof (char) * size + count + 1);
    int j=0;
    i=start +1;
    while (str[start] && start <= end)
    {
        if(str[i] == '|')
        {
            free(copy);
            return("ERROR: syntax error near unexpected token `|'"); // bash: syntax error near unexpected token `|'
        }
        copy[j] = str[start];
         if(is_special_char(&str[i]) == 2)
            i++;
        if(is_special_char(&str[start]) ==1 && !(is_space(str[start+1])))
           {
                j++;
                copy[j] = ' ';
           } 
        if(is_special_char(&str[start])==1 && !(is_space(str[start])))
        {       
                j++;
                copy[j] = ' ';
        }
        j++; 
        start++;   
    }
    copy[j] = '\0';
    return copy;
}

int main()
{
    char *str = "cat \" |a \"";
    char *ret;

    ret = separate_by_spaces(str);
    printf("%s\n", ret);
    return (0);
}