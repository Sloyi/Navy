/*
** EPITECH PROJECT, 2021
** my_intlen.c
** File description:
** return lenght of an int
*/

int my_intlen(int res)
{
    int cp = 0;

    if (res == 0)
        cp = 1;
    if (res < 0)
        cp++;
    while (res != 0) {
        res /= 10;
        cp++;
    }
    return (cp);
}
