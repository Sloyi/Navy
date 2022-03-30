/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** dispay strin length
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

int check_len(long long unsigned int nb, int base)
{
    long long int cpt = 0;

    while (nb > 0) {
        cpt++;
        nb = nb / base;
    }
    return cpt;
}
