/*
** EPITECH PROJECT, 2021
** cord_transfer.c
** File description:
** function for transfer
*/

#include "lib/myprint/myprint.h"
#include "includes/sig.h"

void get_cord(char *cord, int *cpt)
{
    if (MSG.usr1 == 1) {
        cord[*cpt] = 1;
        *cpt -= 1;
        reset_sig();
    } else if (MSG.usr2 == 1) {
        cord[*cpt] = 0;
        *cpt -= 1;
        reset_sig();
    }
}

void send_cord(int i)
{
    for (int x = 0; x < 8; x++) {
        usleep(500);
        if ((i & (1 << x)) != 0) {
            kill(MSG.pid, SIGUSR1);
        }
        else {
            kill(MSG.pid, SIGUSR2);
        }
    }
}

void receive_cord(char *cord)
{
    int cpt = 7;
    while (cpt >= 0) {
        pause();
        get_cord(cord, &cpt);
    }
}