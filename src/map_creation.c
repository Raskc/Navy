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

char *get_chars(char c)
{
    char *new = malloc(sizeof(char) * 2);

    new[0] = c;
    new[1] = '\0';
    return (new);
}

void getstronger(int a, int b, int *temp)
{
    if (a > b) {
        temp[0] = a;
        temp[1] = b;
    } else {
        temp[0] = b;
        temp[1] = a;
    }
}

int place_boat(int ***map, int shipnum, int *temp, char *g)
{
    if (((g[3] - 49) != (g[6] - 49)) && ((g[2] - 65) != (g[5] - 65)))
        return (-1);
    if ((g[3] - 49) == (g[6] - 49)) {
        getstronger(g[2] - 65, g[5] - 65, temp);
        if ((temp[0] - temp[1]) != shipnum - 1)
            return (-1);
        if (push_boat(map, shipnum, temp, g) == -1)
            return (-1);
    } else {
        getstronger(g[3] - 49, g[6] - 49, temp);
        if ((temp[0] - temp[1]) != shipnum - 1)
            return (-1);
        if (push_boat2(map, shipnum, temp, g) == -1)
            return (-1);
    }
    return (0);
}

int use_line(int ***map, char *g, int value)
{
    int shipnum = 0;
    int *temp = malloc(sizeof(int) * 2);

    if (my_strlen(g) != 8)
        return (-1);
    shipnum = my_getnbr(get_chars(g[0]));
    if (g[1] != ':' || g[4] != ':' || shipnum != value)
        return (-1);
    if ((g[2] < 'A' || g[2] > 'H') || (g[3] < '0' || g[3] > '9'))
        return (-1);
    if ((g[5] < 'A' || g[5] > 'H') || (g[6] < '0' || g[6] > '9'))
        return (-1);
    (*map)[g[3] - 49][g[2] - 65] = shipnum;
    if (place_boat(map, shipnum, temp, g) == -1)
        return (-1);
    return (0);
}

int **init_map(char *argv)
{
    FILE *stream = fopen(argv, "r");
    char *line = NULL;
    int count = 2;
    size_t len = 0;
    ssize_t nread;
    int **map = load_map();

    if (stream == NULL)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        nread = getline(&line, &len, stream);
        if (nread == -1)
            return (NULL);
        if (use_line(&map, line, count) == -1)
            return (NULL);
        count++;
    }
    if (getline(&line, &len, stream) != -1)
        return (NULL);
    return (map);
}
