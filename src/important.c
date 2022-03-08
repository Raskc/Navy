/*
** EPITECH PROJECT, 2021
** pro
** File description:
** pro
*/
#include "my.h"
#include "navyf.h"
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int setup(char **argv, navy_t *gl_d)
{
    int **map;

    if (my_getnbr(argv[1]) != -1) {
        map = init_map(argv[2]);
    } else {
        map = init_map(argv[1]);
    }
    if (map == NULL)
        return (-1);
    (*gl_d).otherpid = 0;
    (*gl_d).othmap = load_map();
    (*gl_d).mymap = map;
    (*gl_d).hiten = 0;
    (*gl_d).hitme = 0;
    (*gl_d).connected = 0;
    (*gl_d).data = my_strdup("");
    return (0);
}

int is_type(char **argv, navy_t *gl_d)
{
    if (my_getnbr(argv[1]) != -1) {
        (*gl_d).otherpid = my_getnbr(argv[1]);
        send_bin(CONNECTION_SIG, gl_d);
        return (my_getnbr(argv[1]));
    }
    return (0);
}

void help(void)
{
    my_printf("USAGE\n");
    my_printf("     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("     first_player_pid: only for the 2nd player.");
    my_printf("pid of the first player.\n");
    my_printf("     navy_positions: file representing the ");
    my_printf("the positions of the ships.\n");
}

int verif_win(int value, int *check)
{
    if ((*check) == 1) {
        return (1);
    }
    if (value >= 2 && value <= 5) {
        return (1);
    }
    return (0);
}

int did_win(navy_t *gl_d)
{
    if ((*gl_d).hitme == 14) {
        my_printf("\n");
        show_map((*gl_d).mymap, 0);
        show_map((*gl_d).othmap, 1);
        return (0);
    } else {
        return (1);
    }
}
