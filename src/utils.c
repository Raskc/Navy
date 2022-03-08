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

int pid_show(void)
{
    int my_pid = getpid();

    my_printf("my_pid: %i\n", my_pid);
    return (my_pid);
}

int is_charalpha(char c)
{
    if (c >= '1' && c <= '8') {
        return (1);
    }
    return (0);
}

int is_charletter(char c)
{
    if (c >= 'A' && c <= 'H') {
        return (1);
    }
    return (0);
}

void get_data(navy_t *gl_d)
{
    char *letter = malloc(sizeof(char) * 5);
    char *number = malloc(sizeof(char) * 5);
    int e = 0;

    for (int i = 0; i < 4; i++) {
        letter[i] = (*gl_d).data[i];
    }
    for (int i = 4; i < 8; i++) {
        number[e] = (*gl_d).data[i];
        e++;
    }
    number[5] = '\0';
    letter[5] = '\0';
    gl_d->y = get_index(letter, gl_d);
    gl_d->x = get_index(number, gl_d);
}

void can_show(navy_t *gl_d)
{
    if ((*gl_d).turn == 0) {
        show_map((*gl_d).mymap, 0);
        show_map((*gl_d).othmap, 1);
    }
}
