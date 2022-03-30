/*
** EPITECH PROJECT, 2021
** handler.c
** File description:
** init handler
*/

#include "lib/myprint/myprint.h"
#include "includes/sig.h"

void handler_usr1(int sig, siginfo_t *info, void *ucontext)
{
    if (MSG.pid == 0)
        MSG.pid = info->si_pid;
    MSG.usr1 = 1;
}

void handler_usr2(int sig, siginfo_t *info, void *ucontext)
{
    MSG.usr2 = 1;
}

void init_sig(void)
{
    struct sigaction act;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler_usr1;
    sigaction(SIGUSR1, &act, NULL);
    act.sa_sigaction = handler_usr2;
    sigaction(SIGUSR2, &act, NULL);
    my_printf("my_pid: %i\n",getpid());
}

void reset_sig(void)
{
    MSG.usr1 = 0;
    MSG.usr2 = 0;
}
