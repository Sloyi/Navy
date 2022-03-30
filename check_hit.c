/*
** EPITECH PROJECT, 2021
** parsing_cord.c
** File description:
** This program convert cord into char **
*/

#include <stdio.h>
#include "includes/sig.h"
#include "lib/myprint/myprint.h"

char **load_map(char *file);
int conv_2_10(char *num);

int check_hit(char *cord, char **map)
{
    int val = conv_2_10(cord);
    int nbr = val;
    int y = val % 10;
    int x = val / 10;
    display_pos(nbr);
    if (map[y - 1][x - 1] != '.' && map[y - 1][x - 1] != 'x' &&
    map[y - 1][x - 1] != 'o') {
        map[y - 1][x - 1] = 'x';
        my_printf(": hit\n");
        kill(MSG.pid, SIGUSR1);
        my_printf("\n");
        return 1;
    } else {
        if (map[y - 1][x - 1] != 'x')
            map[y - 1][x - 1] = 'o';
        my_printf(": missed\n");
        kill(MSG.pid, SIGUSR2);
        my_printf("\n");
        return 0;
    }
}
