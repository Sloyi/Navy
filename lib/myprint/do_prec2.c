/*
** EPITECH PROJECT, 2021
** do_prec.c
** File description:
** precison maker
*/

#include "myprint.h"

void do_prec_hexa(struct precision prec, long long unsigned int stck, char x)
{
    prec.after -= check_len(stck, 16);
    if (prec.after >= 0)
        prec.before -= (check_len(stck, 16) + prec.after);
    else
        prec.before -= check_len(stck, 16);
    if (prec.before > 0)
        for (int i = 0; i < prec.before; i++)
            my_putchar(' ');
    if (prec.after > 0)
        for (int i = 0; i < prec.after; i++)
            my_putchar('0');
    my_put_hex(stck, x);
}