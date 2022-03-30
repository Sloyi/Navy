##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	my_printf.c          \
		my_putchar.c			\
		my_getnbr.c			\
		my_putstr.c			\
		my_put_nbr.c			\
		my_strlen.c			\
		my_intlen.c                   \
		do_prec.c   \
		do_prec2.c \
		flag.c	\
		convert.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmyprint.a

all:		 $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
