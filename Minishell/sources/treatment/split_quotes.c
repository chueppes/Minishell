#include "../.././includes/minishell.h"

static int    ft_wordlen(char const *s, char c)
{
    int    i;
    int j=0;
    i = 0;
    while (s[i] != '\0' && (s[i] != c && s[i]))
    {
        if (s[i] == '"')
        {
            j = ft_strrchr(s, '"');
            while (i < j && s[i])
                i++;
        }
        else if (s[i] == 39)
        {
            j = ft_strrchr(s, 39);
            while (i < j && s[i])
                i++;
        }
        else
                i++;
    }
    return (i);
}

const char	*check_quotation(const char *s)
{
    int    i;
    int     j;

    i = 0;
	if (s[i] == '"')
	{
		j=ft_strrchr(s, '"');
		while (i <= j && s[i])
			i++;
	}
	else if (s[i] == 39)
	{
		j=ft_strrchr(s, 39);
		while (i <= j && s[i])
			i++;
	}
	return (s+i);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		s = check_quotation(s);
		if (*s != c && i == 0)
		{
			i = 1;
			j++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (j);
}

static char **do_split(char **array, char *str, char c, int j)
{
    int i;
    int len;

    i = 0;
    while (*str)
    {
        if (*str != c)
        {
            len = ft_wordlen(str, c);
            printf("\ntamanho da string:%d\n", len);
            array[j] = malloc(sizeof(char) * (len + 1));
            array[j][len] = '\0';
            while (len--)
            {
                array[j][i] = *str;
                i++;
                str++;
            }
            i = 0;
            j++;
        }
        else
            str++;
    }
    return (array);
}

char **split_quotes(char *str, char c)
{
    int num_words;
    char **array;
    int j;

    j = 0;
    num_words = ft_wordcount(str, c);
    array = malloc(sizeof(char *) * (num_words + 1));
    array = do_split(array, str, c, j);
    array[num_words] = 0;
    return array;
}