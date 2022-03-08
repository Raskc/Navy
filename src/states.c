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

void turn_verif(navy_t *gl_d)
{
    if ((*gl_d).turn == 1) {
        (*gl_d).turn = 0;
    } else {
        (*gl_d).turn = 1;
    }
}

void not_connected(navy_t *gl_d)
{
    char *co = CONNECTION_SIG;

    if (my_strcmp(co, (*gl_d).data) == 0 && (*gl_d).player == 1) {
        my_printf("\n\nenemy connected\n");
        (*gl_d).connected = 1;
        usleep(50000);
        send_bin(CONNECTION_SIG, gl_d);
        usleep(50000);
        (*gl_d).states = 1;
    } else if (my_strcmp(co, (*gl_d).data) == 0 && (*gl_d).player == 2) {
        my_printf("successfully connected\n");
        (*gl_d).connected = 1;
        usleep(50000);
        (*gl_d).states = 2;
    }
}

void tried(navy_t *gl_d, int value)
{
    int x = (*gl_d).remind[0] - 65;
    int y = (*gl_d).remind[1] - 49;
    (*gl_d).othmap[y][x] = value;
}

void connected(navy_t *gl_d)
{
    if (my_strcmp(MISSED_SIG, (*gl_d).data) == 0) {
        tried(gl_d, -1);
        my_printf("%c%c: missed\n", (*gl_d).remind[0], (*gl_d).remind[1]);
        (*gl_d).states = 2;
        turn_verif(gl_d);
    } else if (my_strcmp(HITTED_SIG, (*gl_d).data) == 0) {
        hitted(gl_d);
    } else {
        (*gl_d).states = 4;
    }
}

void result_check(navy_t *gl_d)
{
    if ((*gl_d).connected == 0) {
        not_connected(gl_d);
    } else {
        connected(gl_d);
    }
    get_data(gl_d);
    (*gl_d).data = my_strdup("");
}
