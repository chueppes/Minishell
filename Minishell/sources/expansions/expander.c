#include "../.././includes/minishell.h"

int is_var_expansible(char *str, int i, int sq_open, int dq_open)
{
    int not_dq;
    int is_dq;
    int forbidden_signal;

    // Se uma cadeia de caracteres simples está aberta ou o caractere atual não é '$'
    // ou não há mais caracteres após o sinal de dólar, retorna 0
    if (sq_open || str[i] != '$' || !str[i + 1])
        return 0;

    // Verifica se há algum caractere proibido após o sinal de dólar
    forbidden_signal = ft_strchars_i(str + i + 1, "/~%^{}:;");
    if (forbidden_signal == 0)
        return 0;

    // Verifica se o espaço ou aspas duplas estão presentes após o sinal de dólar,
    // dependendo se uma cadeia de caracteres dupla ou simples está aberta
    not_dq = (ft_strsearch(str + i + 1, " ") && !dq_open);
    is_dq = (ft_strsearch(str + i + 1, "\"") && dq_open);

    // Retorna 1 se uma das condições acima for verdadeira, caso contrário, retorna 0
    return (not_dq || is_dq);
}
//Esta é uma função em linguagem C que expande variáveis ​​em uma determinada string.
// A função recebe dois argumentos: uma string "str" ​​​​e uma estrutura "t_data". 
//A função usa quatro variáveis: "sq_open", "dq_open", " i" , e uma variável contadora "i" inicializada em 0. 
//As variáveis ​​"sq_open" e "dq_open" controlam se as aspas simples ou duplas estão abertas, respectivamente. 
//Se uma variável precisar ser expandida, a função chama a si mesma recursivamente com uma substring da string original, obtida da função "get_substr_var" e da estrutura "t_data".
char *expand_var(char *str, t_data *data)
{
    int is_sq;
    int is_dq;

    is_dq=0;
    is_sq=0;
    i=0;
    while(str[i])
    {
        is_sq = (is_sq + (!is_dq && str[i] == 39)) % 2;
        is_dq = (is_dq + (!is_sq && str[i] == 34)) % 2;
        if(is_var_expansible(str, i, is_dq, is_sq));
            return(expand_var(get_var(str, ++i, data), data));
        i++;
    }
    return(str);
}

char *get_var(char *str, int i, t_data *data)
{
    
}