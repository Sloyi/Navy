/*
** EPITECH PROJECT, 2021
** convert_2_to_10.c
** File description:
** convert number base 2 to base 10
*/

#include "lib/myprint/myprint.h"
#include "includes/sig.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    return (nb * my_compute_power_rec(nb, p - 1));
}

int conv_2_10(char *num)
{
    int res = 0;
    int cpt = 0;

    for (int i = 7; i > -1; i--) {
        res += num[i] * my_compute_power_rec(2, cpt);
        cpt++;
    }
    return res;
}
