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

void verif_win2(int value, int *check)
{
    if (value == 1) {
        (*check)++;
    }
}

int did_othwin(navy_t *gl_d)
{
    if ((*gl_d).hiten == 14) {
        show_map((*gl_d).mymap, 0);
        show_map((*gl_d).othmap, 1);
        return (0);
    } else {
        return (1);
    }
}

int push_boat(int ***map, int shipnum, int *temp, char *g)
{
    while (temp[0] != temp[1]) {
        if ((*map)[g[3] - 49][temp[0]] != 0) {
            return (-1);
        }
        (*map)[g[3] - 49][temp[0]] = shipnum;
        temp[0]--;
    }
    return (0);
}

int push_boat2(int ***map, int shipnum, int *temp, char *g)
{
    while (temp[0] != temp[1]) {
        if ((*map)[temp[0]][g[5] - 65] != 0) {
            return (-1);
        }
        (*map)[temp[0]][g[5] - 65] = shipnum;
        temp[0]--;
    }
    return (0);
}

int check_endgame(navy_t *gl_d, int *win)
{
    if ((*gl_d).states == 8) {
        (*win) = 1;
        return (0);
    } else if ((*gl_d).states == 9) {
        (*win) = 0;
        return (0);
    }
    return (1);
}
