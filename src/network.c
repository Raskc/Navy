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

void send_bin(char *binmes, navy_t *gl_d)
{
    for (int i = 0; binmes[i] != '\0'; i++) {
        if (binmes[i] == '1') {
            kill((*gl_d).otherpid, SIGUSR1);
        } else {
            kill((*gl_d).otherpid, SIGUSR2);
        }
        usleep(1000);
    }
}

void send_info(char *message, navy_t *gl_d)
{
    char *new = "";

    for (int i = 0; i < 2; i++) {
        if (is_charalpha(message[i]) == 1) {
            new = my_concat(new, (*gl_d).bintable[message[i] - 49]);
        } else {
            new = my_concat(new, (*gl_d).bintable[message[i] - 65]);
        }
    }
    send_bin(new, gl_d);
}

int get_index(char *thing, navy_t *gl_d)
{
    for (int i = 0; i < 8; i++) {
        if (my_strcmp(thing, (*gl_d).bintable[i]) == 0) {
            return (i);
        }
    }
    return (0);
}

void check_signal(struct sigaction sig, navy_t *gl_d)
{
    if (sigaction(SIGUSR1, &sig, NULL) != 0)
        return;
    if (sigaction(SIGUSR2, &sig, NULL) != 0)
        return;
    if (my_strlen((*gl_d).data) == 8) {
        result_check(gl_d);
    }
    turn_checking(gl_d);
}
