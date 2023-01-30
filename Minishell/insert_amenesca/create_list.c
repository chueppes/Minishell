#include "./list.h"

int  count_strs(char **strs)
{
    int i;

    i = 0;
    while (strs[i] != NULL)
     i++;
    return (i);
}

int	create_list(t_commands **list, char **array)
{
	int x = count_strs(array);
	int j = 0;
	while (j < x)
	{
		printf("%s\n",array[j]);
		*list->comm
		j++;
	}
	return 0;
}

int main()
{
	t_commands **list;
	*list = NULL;
	char **array;
	array = NULL;
	char *str = "command |command -t -l \"oi 'oi'\" |grep -e oi";
	array = split_quotes(str, '|');
	for (int i = 0; i < 3; i++)
		printf("%s\n", array[i]);
//	list = (t_commands **) malloc(sizeof(t_commands *) * count_strs(array));
	create_list(list, array);
	while (*list)
	{
		printf("%s\n", (*list)->cmd);
		*list = (*list)->next;
	}
	return (0);
}