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

static navy_t gl_d;

void handler(int signo, siginfo_t *info, void *context)
{
    if (gl_d.otherpid == 0) {
        gl_d.otherpid = info->si_pid;
    }
    if (signo == SIGUSR1) {
        gl_d.data = my_concat(gl_d.data, my_strdup("1"));
    } else if (signo == SIGUSR2) {
        gl_d.data = my_concat(gl_d.data, my_strdup("0"));
    }
}

int game_loop(void)
{
    int bytes = 0;
    char *buff = malloc(sizeof(char) * 32);
    struct sigaction sig;
    int win = 0;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = handler;
    while (1) {
        check_signal(sig, &gl_d);
        if (check_endgame(&gl_d, &win) == 0)
            break;
        bytes = read(0, buff, 31);
        if (bytes == 0)
            break;
        if (gl_d.states == 3) {
            attack(buff, &gl_d);
            buff = malloc(sizeof(char) * 32);
        }
    }
    return (win);
}

int navy(int argc, char **argv)
{
    char *bin[8] = {"1000","0100","0010","0001","1100","0110","0011","1110"};

    if (my_getnbr(argv[1]) == -1 && argc != 2)
        return (-1);
    if (setup(argv, &gl_d) == -1) {
        return (-1);
    }
    pid_show();
    gl_d.bintable = bin;
    is_type(argv, &gl_d);
    if (gl_d.otherpid == 0) {
        gl_d.player = 1;
        my_printf("waiting for enemy connection...");
    } else {
        gl_d.player = 2;
    }
    return (game_loop());
}

int main(int argc, char **argv)
{
    int stored = 0;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help();
        return (0);
    }
    if (argc > 1 && argc <= 3) {
        stored = navy(argc, argv);
        if (stored == -1)
            return (84);
    } else {
        return (84);
    }
    return (stored);
}
