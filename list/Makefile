##
## EPITECH PROJECT, 2023
## lib_list
## File description:
## Makefile
##

SRC_DOUBLE	=	double_link/src/double_addons.c	\
				double_link/src/double_link.c	\
				double_link/src/double_link2.c	\
				double_link/src/double_link3.c

SRC_SIMPLE	=	simple_link/src/addons.c	\
				simple_link/src/simple_link.c	\
				simple_link/src/simple_link2.c	\
				simple_link/src/simple_link3.c

OBJ_DOUBLE	=	$(SRC_DOUBLE:.c=.o)

OBJ_SIMPLE	=	$(SRC_SIMPLE:.c=.o)

NAME	=	"liblist_s.a"

NAME_D	=	"liblist_d.a"

simple: $(OBJ_SIMPLE)
	ar rc $(NAME) $(OBJ_SIMPLE)
	mv $(NAME) ../
	cp simple_link/include/list.h ../../include/
	rm $(OBJ_SIMPLE)

double: $(OBJ_DOUBLE)
	ar rc $(NAME_D) $(OBJ_DOUBLE)
	mv $(NAME_D) ../
	cp double_link/include/double_list.h ../../include/
	rm $(OBJ_DOUBLE)

clean:
	rm -rf ../$(NAME)
	rm -rf ../$(NAME_D)

fclean: clean
