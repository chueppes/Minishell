#include <stdlib.h>
char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	int size=0;

    while(s2[size])
     size++;
    s1=malloc(size);
    // if(!s1)
    //     return(NULL);
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}