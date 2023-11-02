##
## EPITECH PROJECT, 2023
## lib_list
## File description:
## Makefile
##

SRC	=	double_link/src/double_link.c	\
		double_link/src/double_link2.c	\
		double_link/src/double_link3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	"liblist.a"

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../$(NAME)
	rm -rf $(NAME)

re: fclean all
