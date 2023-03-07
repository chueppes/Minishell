#include "../.././includes/minishell.h"

char	*get_var_value(char *str, int i, t_data *data)
{
 
	char	*aux;
    char	*path;
	char	*var;
	int		position;
	int		size_var;

	position = ft_strnchar(str + i, "|\"\'$?>< ") + (ft_strchr("$?", str[i]) != 0);
	if (position == -1)
		position = ft_strlen(str) - 1;
	aux = ft_substr(str, 0, i - 1);
	size_var = ft_strnchar(str + i, "|\"\'$?>< ");
	var = ft_getenv(str + i, data->minishell_envp, size_var);
	if (!var && str[i] != '?')
	{
		var = malloc(2);
		var[0] = '\n';
		var[1] = '\0';
	}
	if (!var && str[i] == '?')
		var = ft_itoa(global);
	path = ft_strjoin(aux, var);
	free(aux);
	if(position == (int)ft_strlen(str)-1)
		i=1;
	aux = ft_strjoin(path, str + i + position);
	free(var);
	free(path);
	free(str);
	return (aux);
}

int	should_var_be_expanded(char *str, int i, int sq_open, int dq_open)
{
	int	forbidden_char;
	int	double_quote_negative;
	int	double_quote_positive;

	if (sq_open || str[i] != '$' || !str[i + 1])
		return (0);
	forbidden_char = ft_strnchar(str + i + 1, "/~%^{}:;");
	if (forbidden_char == 0)
		return (0);
	double_quote_negative = (ft_strnchar(str + i + 1, " ") && !dq_open);
	double_quote_positive = (ft_strnchar(str + i + 1, "\"") && dq_open);
	return (double_quote_negative || double_quote_positive);
}

char	*expand_vars(char *str, t_data *data)
{
   
	int	sq_open;
	int	dq_open;
	int	i;

	sq_open = 0;
	dq_open = 0;
	i = 0;
	while (str && str[i])
	{
		if (!dq_open && str[i] == 39)
            sq_open = (sq_open + 1) % 2;
        if (!sq_open && str[i] == '"') 
            dq_open = (dq_open + 1) % 2;
			//STR NON EXISTENT
		if (should_var_be_expanded(str, i, sq_open, dq_open))
			return (expand_vars(get_var_value(str, ++i, data), data));
		i++;
	}
	return (str);
}
