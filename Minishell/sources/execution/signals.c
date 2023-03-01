#include "../.././includes/minishell.h"

void sigint_should_do(int signal)
{
    if(signal == SIGINT)
    {
        global = 128 +signal;
        ioctl(STDIN_FILENO, TIOCSTI, "\n");
        rl_replace_line("", 0);
        rl_on_new_line();
    }
}

void sigint_parser(void)
{
    signal(SIGINT, sigint_should_do);
   	signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
}
