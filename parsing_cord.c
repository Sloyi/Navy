/*
** EPITECH PROJECT, 2021
** parsing_cord.c
** File description:
** This program convert cord into char **
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void put_point_in_map(char **map)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
    }
}

void fill_the_map(char **map, char **f, int i)
{
    if (f[i][2] == f[i][5]) {
        for (int j = (f[i][3] - '0') - 1; j < (f[i][6] - '0'); j++) {
            map[j][f[i][2] - 65] = f[i][0];
        }
    } else {
        for (int j = f[i][2] - 65; j < f[i][5] - 65 + 1; j++) {
            map[f[i][3] - '0' - 1][j] = f[i][0];
        }
    }
}

void put_ship_in_map(char **map, char **f)
{
    put_point_in_map(map);
    for (int i = 0; i < 4; i++) {
        fill_the_map(map, f, i);
    }
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **s;
    s = malloc(sizeof(char *) * (nb_rows + 1));
    s[nb_rows] = NULL;

    for (int i = 0; i < nb_rows; i++) {
        s[i] = malloc(sizeof(char) * (nb_cols + 1));
        s[i][nb_cols] = '\0';
    }
    return s;
}

char **load_map(char *file)
{
    char **map = mem_alloc_2d_array(8, 8);
    char **content_file = mem_alloc_2d_array(4, 8);
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;
    for (int i = 0; i < 4; i++)
        if (read(fd, content_file[i], 8) == -1)
            return NULL;
    put_ship_in_map(map, content_file);
    return map;
}