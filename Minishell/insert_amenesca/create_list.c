#include "./list.h"

int	create_list(t_data *minishell)
{
	(void)minishell;
	return (2);
	//lstadd_back_command();
}

int main()
{
	char *str = "command | command -t -l \"oi \'oi\'\" | grep -e oi";
	printf("%s\n", str);
	//t_data minishell;
	//create_list(&minishell);
}