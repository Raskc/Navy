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

int **load_map(void)
{
    int **map = malloc(sizeof(int*) * 8);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * 8);
    }
    for (int i = 0; i < 8; i++) {
        for (int e = 0; e < 8; e++) {
            map[i][e] = 0;
        }
    }
    return (map);
}

int **load_mymap(void)
{
    int **map = malloc(sizeof(int*) * 8);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * 8);
    }
    for (int i = 0; i < 8; i++) {
        for (int e = 0; e < 8; e++) {
            map[i][e] = 0;
        }
    }
    map[1][1] = 2;
    return (map);
}

void show_rightchar(int num, int index)
{
    if (num == 0) {
        my_printf(".");
    } else if (num == 1) {
        my_printf("x");
    }
    if (num == -1) {
        my_printf("o");
    } else if (num >= 2 && num <= 5) {
        my_printf("%i", num);
    }
    if (index != 7) {
        my_printf(" ");
    }
}

void show_map(int **map, int tec)
{
    if (tec == 0) {
        my_printf("\nmy positions:\n");
    } else {
        my_printf("\nenemy's positions:\n");
    }
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%i|", i + 1);
        for (int e = 0; e < 8; e++) {
            show_rightchar(map[i][e], e);
        }
        my_printf("\n");
    }
}
