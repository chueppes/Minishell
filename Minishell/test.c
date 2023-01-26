static int    ft_wordlen(char const *s, char c)
{
    int    i;
int j=0;
    i = 0;
    while (s[i] != c && s[i] != '\0')
    {
        if (s[i] == '"')
        {
            j = ft_strrchr(s, '"');
            printf("\ntamanho final:%d", j);
            while (i <= j && s[i])
                i++;
        }
        else if (s[i] == 39)
        {
            j = ft_strrchr(s, 39);
            while (i <= j && s[i])
                i++;
        }
       i++;
    }
    return (i);
}

int	ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char)c)
	{	
		if (i == 0)
			return (0);
		i--;
	}
	return (i);
}

#include <stdio.h>

int main(void)
{
    char * str = "\" "loucura >>  |  " v " ||  |  banana >>  <  "bdfsfsd\" dflkdfdslfskn lksdl\"";
    ft_wordlen(str, " ");
}