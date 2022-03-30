/*
** EPITECH PROJECT, 2021
** get_cord_attack.c
** File description:
** get cord of the attack
*/

#include "includes/sig.h"
#include "lib/myprint/myprint.h"

int get_cord_output(void)
{
    char s[3];
    int val = 0;
    if (read(0, s, 3) == -1 || s[2] != '\n' ||
    s[0] < 'A' || s[0] > 'H' || s[1] < '1' || s[1] > '8') {
        my_printf("wrong position\n");
        return -1;
    }
    val = val * 10 + (s[0] - '@');
    val = val * 10 + (s[1] - '0');
    return val;
}