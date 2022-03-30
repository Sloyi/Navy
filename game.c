/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** function for game loop
*/

#include "lib/myprint/myprint.h"
#include "includes/sig.h"

void disp_game(char **map1, char **map2)
{
    my_printf("my positions:\n");
    disp_map(map1);
    my_printf("enemy's positions:\n");
    disp_map(map2);
}

void change_turn(int *turn, int *send)
{
    if (*turn == 1)
        *turn = 2;
    else
        *turn = 1;
    *send = -1;
}

void attack(int player, int *send, int turn)
{
    if (player == turn) {
        while (*send == -1) {
            my_printf("attack: ");
            *send = get_cord_output();
        }
        send_cord(*send);
        usleep(500);
    }
}

void get_hit(char *cord, int *cpt_you, char **map1)
{
    my_printf("waiting for enemy's attack...\n");
    receive_cord(cord);
    if (check_hit(cord, map1) == 1)
        *cpt_you += 1;
}

void i_hit(int *cpt_my, char **map2, int send)
{
    if (MSG.usr1 == 1) {
        *cpt_my += 1;
        display_pos(send);
        my_printf(": hit\n");
        if (map2[(send % 10) - 1][(send / 10) - 1] != 'x')
            map2[(send % 10) - 1][(send / 10) - 1] = 'x';
    } else if (MSG.usr2 == 1) {
        display_pos(send);
        my_printf(": missed\n");
        map2[(send % 10) - 1][(send / 10) - 1] = 'o';
    }
    my_printf("\n");
    reset_sig();
}