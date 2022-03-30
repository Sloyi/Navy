/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put a number
*/

#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(long long int nb)
{
    long long int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar('0' + mod);
    } else {
        my_putchar('0' + nb);
    }
}

int my_put_nbr_unsigned(long long unsigned int nb)
{
    long long unsigned int mod;

    if (nb > 9) {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar('0' + mod);
    } else {
        my_putchar('0' + nb);
    }
}

void my_put_base(long long unsigned int nb, int base)
{
    if (nb / base != 0)
        my_put_base(nb / base, base);
    my_putchar((nb % base) + '0');
}

void my_put_hex(long long unsigned int nb, char x)
{
    if (nb / 16 != 0)
        my_put_hex(nb / 16, x);
    if (nb % 16 > 9 && x == 'X')
        my_putchar((nb % 16) + 55);
    if (nb % 16 > 9 && x == 'x')
        my_putchar((nb % 16) + 87);
    if (nb % 16 < 10)
        my_putchar((nb % 16) + '0');
}