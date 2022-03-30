/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** get a number
*/

int my_getnbr(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res = res * 10;
        res += str[i] - '0';
    }
    return (res);
}

int my_getnbrprec(char const *str, int *i)
{
    int res = 0;
    int neg = 0;

    for (; str[*i] == '-' || (str[*i] >= '0' && str[*i] <= '9'); *i += 1) {
        if (str[*i] == '-') {
            neg = 1;
            *i += 1;
        }
        res = res * 10;
        res += str[*i] - '0';
    }
    if (neg == 0)
        return (res);
    else
        return (res * (-1));
}