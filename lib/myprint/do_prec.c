/*
** EPITECH PROJECT, 2021
** do_prec.c
** File description:
** precison maker
*/

#include "myprint.h"

void do_prec_int(struct precision prec, long long int stck)
{
    prec.after -= my_intlen(stck);
    if (prec.after >= 0)
        prec.before -= (my_intlen(stck) + prec.after);
    else
        prec.before -= my_intlen(stck);
    if (prec.before > 0)
        for (int i = 0; i < prec.before; i++)
            my_putchar(' ');
    if (prec.after > 0)
        for (int i = 0; i < prec.after; i++)
            my_putchar('0');
    my_put_nbr(stck);
}

void do_prec_uint(struct precision prec, long long unsigned int stck)
{
    prec.after -= my_intlen(stck);
    if (prec.after >= 0)
        prec.before -= (my_intlen(stck) + prec.after);
    else
        prec.before -= my_intlen(stck);
    if (prec.before > 0)
        for (int i = 0; i < prec.before; i++)
            my_putchar(' ');
    if (prec.after > 0)
        for (int i = 0; i < prec.after; i++)
            my_putchar('0');
    my_put_nbr_unsigned(stck);
}

void do_prec_char(struct precision prec, int stck)
{
    prec.before -= 1;
    if (prec.before > 0)
        for (int i = 0; i < prec.before; i++)
            my_putchar(' ');
    my_putchar(stck);
}

void do_prec_chare(struct precision prec, char *stck)
{
    prec.before -= my_strlen(stck);
    if (prec.before > 0)
        for (int i = 0; i < prec.before; i++)
            my_putchar(' ');
    my_putstr(stck);
}

void do_precision_base(struct precision prec,
long long unsigned int stck, int base)
{
    prec.after -= check_len(stck, base);
    if (prec.after >= 0)
        prec.before -= (check_len(stck, base) + prec.after);
    else
        prec.before -= check_len(stck, base);
    if (prec.before > 0)
        for (int i = 0; i < prec.before; i++)
            my_putchar(' ');
    if (prec.after > 0)
        for (int i = 0; i < prec.after; i++)
            my_putchar('0');
    my_put_base(stck, base);
}