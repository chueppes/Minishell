int is_special_char(char c)
{
    if(c == '|' || c == '>' || c == '<')
        return(1);
    else
        return(0);
}

int is_space(int c)
{
     if(c == 32 || (c >= 9 && c <= 13))
        return(1);
    else
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
    start = i-1;
    while (str[i])
    {
        if((is_special_char(str[i])) && (!is_space(str[i+1])) && (!is_space(str[i-1])))
            count++;
        i++;
    }
    while(is_space(str[--i]));
    size += end - start;
    copy = malloc(sizeof (char *) * size + count + 1);
    int j=0;
    while (str[++start])
    {
        if(str[start] == '|')
            return(1); // bash: syntax error near unexpected token `|'
        copy[j] = str[i];
        if(is_special_char(str[i+1]) && !(is_space(str[i])))
           {
                j++;
                copy[j] = ' ';
           } 
        if(is_special_char(str[i]) && !(is_space(str[i+1])))
        {       
                j++;
                copy[j] = ' ';
        }
        j++;    
    }
}
