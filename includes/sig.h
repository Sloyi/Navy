/*
** EPITECH PROJECT, 2021
** sig.h
** File description:
** prototype and struct for navy
*/

#ifndef SIG_H_
    #define SIG_H_
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <signal.h>
    #include <stdlib.h>

typedef struct MSG {
    int usr1;
    int usr2;
    int pid;
}MSG_t;

extern struct MSG MSG;

void disp_map(char **map);
void disp_game(char **map1, char **map2);
void change_turn(int *turn, int *send);
void attack(int player, int *send, int turn);
void get_hit(char *cord, int *cpt_you, char **map1);
void i_hit(int *cpt_my, char **map2, int send);
void display_pos(int nbr);
int check_hit(char *cord, char **map);
int get_cord_output(void);
void put_point_in_map(char **map);
void send_cord(int i);
void receive_cord(char *cord);
void get_cord(char *cord, int *cpt);
int conv_2_10(char *num);
void fill_the_map(char **map, char **f, int i);
void put_ship_in_map(char **map, char **f);
char **load_map(char *file);
void reset_sig(void);
void init_sig(void);
int host(char **map1, char **map2);
int  client(int host_pid, char **map1, char **map2);
int verif_ships_cord(char *f);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
int is_letter(char c);
int verif_cord(char **content_file);
int verif_file(char *file);

#endif