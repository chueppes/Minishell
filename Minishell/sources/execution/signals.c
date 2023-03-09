#include "../.././includes/minishell.h"

/*void sigint_should_do(int signal)
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
}*/

void    child_signals(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}

void    handle_sig(int sig, siginfo_t *info, void *algo)
{
    (void)algo;
    (void)*info;
    if (sig == SIGINT)
    {
        global = 130;
        if (RL_ISSTATE(RL_STATE_READCMD))
            ioctl(STDIN_FILENO, TIOCSTI, "\n");
        else
            write(1, "\n", 1);
        rl_replace_line("", 0);
        rl_on_new_line();
    }
}

void    signals(void)
{
    struct sigaction    act;

    act.sa_sigaction = (void *)handle_sig;
    act.sa_flags = SA_SIGINFO;
    signal(SIGQUIT, SIG_IGN);
    sigaction(SIGINT, &act, NULL);
}
