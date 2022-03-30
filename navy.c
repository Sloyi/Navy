/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** navy
*/

#include "includes/sig.h"
#include "lib/myprint/myprint.h"

int error_handling(int gc, char **gv)
{
    if (verif_file(gv[1]) == 84)
        return 84;
    return 0;
}

char *get_path(int gc, char **gv)
{
    if (gc == 3) {
        return gv[2];
    } else if (gc == 2) {
        return gv[1];
    } else
        return NULL;
}

int main(int gc, char **gv)
{
    char **map1;
    char *map_path = get_path(gc, gv);
    char **map2 = mem_alloc_2d_array(8, 8);

    if (verif_file(map_path) == 84)
        return 84;
    put_point_in_map(map2);
    map1 = load_map(map_path);
    if (map1 == NULL)
        return 84;
    init_sig();
    if (gc == 2)
        return (host(map1, map2) == 0) ? 0 : 1;
    if (gc == 3)
        return (client(my_getnbr(gv[1]), map1, map2) == 0) ? 0 : 1;
}
