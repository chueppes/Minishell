#include "./list.h"

int	create_list(t_data *minishell)
{
	(void)minishell;
	return (2);
	//lstadd_back_command();
}

int main()
{
	t_data *minishell;
	minishell = (t_data *)malloc(sizeof(t_data));
	char *str = "command | command -t -l \"oi 'oi'\" | grep -e oi";
	printf("%s\n", str);
	//t_data minishell;
	//create_list(&minishell);

	free(minishell);
	return (0);
}