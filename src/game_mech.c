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

void attack_mode(navy_t *gl_d)
{
    gl_d->states = 3;
    my_printf("attack: ");
}

int is_attack(char *buff)
{
    if (my_strlen(buff) == 3 && is_charletter(buff[0]) == 1) {
        if (is_charalpha(buff[1]) == 1) {
            return (1);
        }
    }
    return (0);
}

void attack(char *buff, navy_t *gl_d)
{
    if (is_attack(buff) == 1) {
        send_info(buff, gl_d);
        (*gl_d).remind = buff;
        (*gl_d).states = 6;
    } else {
        my_printf("wrong position\n");
        attack_mode(gl_d);
    }
}

void did_hit(navy_t *gl_d)
{
    int pos = (*gl_d).mymap[(*gl_d).x][(*gl_d).y];

    my_printf("\n%c", (*gl_d).y + 65);
    my_printf("%c", (*gl_d).x + 49);
    if (pos >= 2 && pos <= 5) {
        (*gl_d).mymap[(*gl_d).x][(*gl_d).y] = 1;
        (*gl_d).hitme += 1;
        my_printf(": hit");
        send_bin(HITTED_SIG, gl_d);
        if (did_win(gl_d) == 0) {
            my_printf("\nEnemy won\n");
            (*gl_d).states = 8;
        }
    } else {
        (*gl_d).mymap[(*gl_d).x][(*gl_d).y] = -1;
        my_printf(": missed");
        send_bin(MISSED_SIG, gl_d);
    }
}

void turn_checking(navy_t *gl_d)
{
    if ((*gl_d).states == 1) {
        can_show(gl_d);
        my_printf("\n");
        attack_mode(gl_d);
    } else if ((*gl_d).states == 2) {
        can_show(gl_d);
        my_printf("\nwaiting for enemy's attack...");
        (*gl_d).states = 7;
    }
    if ((*gl_d).states == 4) {
        did_hit(gl_d);
        if ((*gl_d).states == 4) {
            turn_verif(gl_d);
            (*gl_d).states = 1;
            my_printf("\n");
            turn_checking(gl_d);
        }
    }
}
