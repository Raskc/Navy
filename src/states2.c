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

void hitted(navy_t *gl_d)
{
    tried(gl_d, 1);
    (*gl_d).hiten += 1;
    my_printf("%c%c: hit\n", (*gl_d).remind[0], (*gl_d).remind[1]);
    if (did_othwin(gl_d) == 0) {
        my_printf("\nI won\n");
        (*gl_d).states = 9;
    } else {
        (*gl_d).states = 2;
        turn_verif(gl_d);
    }
}
