/*
** EPITECH PROJECT, 2021
** file_verif_pos.c
** File description:
** This program verif the coordonates are valide
*/

#include <stdlib.h>
#include "../includes/sig.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int verif_ships_cord(char *f)
{
    if (f[2] == f[5]) {
        if ((f[6] - '0') != ((f[3] - '0') + (f[0] - '0')) - 1)
            return 84;
    } else {
        if (f[5] != f[2] + (f[0] - '0') - 1)
            return 84;
    }
    return 0;
}

int is_letter(char c)
{
    return (c == 'A' || c == 'B' || c == 'C' ||
    c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H');
}

int verif_cord(char **content_file)
{
    for (int i = 0; i < 4; i++) {
        if (content_file[i][4] != ':' || content_file[i][1] != ':' ||
            content_file[i][7] != '\n')
            return 84;
        if (content_file[i][0] < '2' || content_file[i][0] > '5')
            return 84;
        if (!is_letter(content_file[i][2]) || !is_letter(content_file[i][5]))
            return 84;
        if (content_file[i][3] < '1' || content_file[i][6] > '8')
            return 84;
        if (content_file[i][2] != content_file[i][5]
            && content_file[i][3] != content_file[i][6])
            return 84;
        if (verif_ships_cord(content_file[i]) == 84)
            return 84;
    }
    return 0;
}

int check_nbr_ship(char **map)
{
    int cpt_2 = 0;
    int cpt_3 = 0;
    int cpt_4 = 0;
    int cpt_5 = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][0] == '2')
            cpt_2 += 1;
        if (map[i][0] == '3')
            cpt_3 += 1;
        if (map[i][0] == '4')
            cpt_4 += 1;
        if (map[i][0] == '5')
            cpt_5 += 1;
    }
    return (cpt_2 == 1 && cpt_3 == 1 && cpt_4 == 1 && cpt_5 == 1) ? 0 : 84;
}

int verif_file(char *file)
{
    char **content_file = mem_alloc_2d_array(4, 8);
    char s[5];
    int fd = open(file, O_RDONLY);
    for (int i = 0; i < 4; i++)
        if (read(fd, content_file[i], 8) == -1)
            return 84;
    if (read(fd, s, 1) == -1 || s[0] != '\0')
        return 84;
    if (verif_cord(content_file) == 84)
        return 84;
    if (check_nbr_ship(content_file) == 84)
        return 84;
    free(content_file);
    return 0;
}