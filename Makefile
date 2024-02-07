##
## EPITECH PROJECT, 2023
## make file
## File description:
## compile all *.c
##

SRC	=	my_ls.c \
		my_sort_array.c \
		my_strcmp_alpha.c \
		perm.c \
		display.c \
		reverse.c \
		my_ls_file.c

OBJ_TEST=	$(SRC_TEST:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS += -g

all:	$(NAME)

$(NAME):	$(OBJ)
	cd my_printf/ && make
	gcc -o $(NAME) $(OBJ) -L./my_printf/ -lmy

clean:
	cd my_printf/ && make clean
	rm -f $(OBJ)

fclean:		clean
	cd my_printf/ && make fclean
	rm -f $(NAME)

re:	fclean all
