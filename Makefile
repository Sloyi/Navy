##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	connect.c \
		error_handling/file_verif_pos.c \
		parsing_cord.c \
		handler.c \
		cord_transfer.c			\
		convert_2_to_10.c		\
		get_cord_attack.c			\
		check_hit.c			\
		conv_int_pos.c	\
		game.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	$(NAME)

lib:
		make -C lib/myprint/.

tests_run: $(NAME)
	gcc $(SRC) tests/test_pushswap.c -lcriterion --coverage -Llib/my -lmy
	./a.out

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) navy.c $(OBJ) -Llib/myprint/. -lmyprint

clean:
	make clean -C lib/myprint/.
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/myprint/.
	rm -f $(NAME)

re: fclean all

.PHONY: lib
