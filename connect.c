/*
** EPITECH PROJECT, 2021
** connect.c
** File description:
** handle connection between 2 programme
*/

#include "lib/myprint/myprint.h"
#include "includes/sig.h"

struct MSG MSG = {0, 0, 0};

void disp_map(char **map)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 1; i < 9; i++)
        my_printf("%i|%c %c %c %c %c %c %c %c\n", i, map[i - 1][0],
        map[i - 1][1], map[i - 1][2], map[i - 1][3], map[i - 1][4],
        map[i - 1][5], map[i - 1][6], map[i - 1][7]);
    my_printf("\n");
}

int game(int player, char **map1, char **map2)
{
    char cord[8];
    int turn = 1;
    int send = -1;
    int cpt_my = 0;
    int cpt_you = 0;

    while (cpt_my != 14 && cpt_you != 14) {
        if (turn == 1)
            disp_game(map1, map2);
        attack(player, &send, turn);
        if (player != turn)
            get_hit(cord, &cpt_you, map1);
        if (player == turn) {
            i_hit(&cpt_my, map2, send);
            reset_sig();
        }
        change_turn(&turn, &send);
    }
    return (cpt_my == 14) ? 0 : 1;
}

int host(char **map1, char **map2)
{
    my_printf("waiting for enemy connection...\n\n");
    pause();
    my_printf("enemy connected\n\n");
    kill(MSG.pid, SIGUSR1);
    reset_sig();
    if (game(1, map1, map2) == 0) {
        my_printf("I won\n");
        return 0;
    } else {
        my_printf("Enemy won\n");
        return 1;
    }
}

int client(int host_pid, char **map1, char **map2)
{
    char cord[8];
    kill(host_pid, SIGUSR1);
    pause();
    my_printf("successfully connected\n\n");
    reset_sig();
    if (game(2, map1, map2) == 0) {
        my_printf("I won\n");
        return 0;
    } else {
        my_printf("Enemy won\n");
        return 1;
    }
}