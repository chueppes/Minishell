#include "../.././includes/minishell.h"

char	*get_path_value(char *str, int i, t_data *data)
{
 
	char	*aux;
	char	*path;
	char	*var;

	aux = ft_substr(str, 0, i);
	var = ft_getenv("HOME", data->minishell_envp, 4);
	path = ft_strjoin(aux, var);
	free(aux);
	aux = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	str = ft_strjoin(path, aux);
	free(aux);
	free(path);
	free(var);
	return (str);
}

int	should_path_be_expanded(char *str, int i, int sq_open, int dq_open)
{

	if (sq_open || dq_open)
		return (0);
	if (str[i] != '~')
		return (0);
	if (i != 0 && str[i - 1] == '$')
		return (0);
	return (1);
}

char	*expand_path(char *str, t_data *data)
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
		if (should_path_be_expanded(str, i, sq_open, dq_open))
			return (expand_path(get_path_value(str, i, data), data));
		i++;
	}
	return (str);
}

