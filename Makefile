##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## tqt c le makefile
##

SRC	=	src/main.c \
		src/utils.c \
		src/game_mech.c \
		src/network.c \
		src/important.c \
		src/states.c \
		src/endgame.c \
		src/states2.c \
		src/map_creation.c \
		src/gestion_map.c

CC	=	gcc

CFLAGS	=	-Wall -Wextra -g -I./include -L./lib/my -lmy


LDFLAGS	= -L./lib/my -lmy


OBJ	=	$(SRC:.c=.o)

NAME	= navy

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	make clean

clean:
	rm -f $(OBJ)
	find . -name "*.gcda" -delete
	find . -name '*[#~#]' -delete
	find . -name "*.gcno" -delete
	find . -name "*.o" -delete

fclean: clean
		rm -f $(NAME)

re:	fclean all
