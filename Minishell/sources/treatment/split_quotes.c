#include "../.././includes/minishell.h"

static size_t	ft_len(char const *s, int c)
{
	size_t	j;

	j = 0;
	while (s[j] != c && s[j] != '\0')
	{
		if (s[j] == '"')
		{
			j++;
			while (s[j] != '"')
				j++;
		}
		if (s[j] == 39)
		{
			j++;
			while (s[j] != 39)
				j++;
		}
		j++;
	}
	return (j);
}

static const char	*check_quotation(const char *s)
{
	if (*s == '"')
	{
		s++;
		while (*s != '"')
			s++;
	}
	if (*s == 39)
	{
		s++;
		while (*s != 39)
			s++;
	}
	return (s);
}

static size_t	ft_wordcount(char const *s, char c)
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

char	**split_quotes(char const *s, char c)
{
	char	**str;
	size_t	j;
	char	*str1;
	int		substr;

	str1 = (char *)s;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < ft_wordcount(s, c))
	{
		while (*str1 == c && *str1)
			str1++;
		substr = ft_len(str1, c);
		str[j] = ft_substr(str1, 0, substr);
		j++;
		str1 += substr;
	}
	str[j] = NULL;
	return (str);
}
