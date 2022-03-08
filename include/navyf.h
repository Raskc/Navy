/*
** EPITECH PROJECT, 2021
** tes
** File description:
** tt
*/
#include <signal.h>

#ifndef NAVYF_H_
    #define NAVYF_H_
    #define CONNECTION_SIG "00000000"
    #define HITTED_SIG "10011001"
    #define MISSED_SIG "01110111"
    #define GAMEND_SIG "11111111"
typedef struct navy_s {
    char *data;
    int otherpid;
    int connected;
    int player;
    int **mymap;
    int **othmap;
    char *remind;
    int hiten;
    int hitme;
    int y;
    int x;
    int states;
    int turn;
    char **bintable;
}navy_t;
void get_data(navy_t *gl_d);
void show_map(int **map, int tec);
int **load_map(void);
void result_check(navy_t *gl_d);
int is_charalpha(char c);
int is_charletter(char c);
void check_signal(struct sigaction sig, navy_t *gl_d);
void attack(char *buff, navy_t *gl_d);
void send_bin(char *binmes, navy_t *gl_d);
int get_index(char *thing, navy_t *gl_d);
void send_info(char *message, navy_t *gl_d);
int pid_show(void);
int setup(char **argv, navy_t *gl_d);
int is_type(char **argv, navy_t *gl_d);
void turn_checking(navy_t *gl_d);
void help(void);
void can_show(navy_t *gl_d);
void turn_verif(navy_t *gl_d);
int did_win(navy_t *gl_d);
int **load_mymap(void);
int did_othwin(navy_t *gl_d);
void hitted(navy_t *gl_d);
void tried(navy_t *gl_d, int value);
int **init_map(char *argv);
int push_boat(int ***map, int shipnum, int *temp, char *g);
int push_boat2(int ***map, int shipnum, int *temp, char *g);
int check_endgame(navy_t *gl_d, int *win);
#endif /* NAVYF_H_ */
