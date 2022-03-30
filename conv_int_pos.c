/*
** EPITECH PROJECT, 2021
** display_pos.c
** File description:
** convert int to coordonate && display it
*/

#include "lib/myprint/myprint.h"
#include "includes/sig.h"

void display_pos(int nbr)
{
    char cord[3];
    cord[2] = '\0';
    cord[1] = (nbr % 10) + '0';
    nbr /= 10;
    cord[0] = (nbr % 10) + '@';
    my_printf("%s", cord);
}