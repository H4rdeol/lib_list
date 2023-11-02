##
## EPITECH PROJECT, 2023
## lib_list
## File description:
## Makefile
##

SRC		=	double_link/src/double_link.c	\
			double_link/src/double_link2.c	\
			double_link/src/double_link3.c

TEST_SRC	=	tests/test_push_back.c	\
				tests/test_push_front.c	\
				tests/test_pop_front.c	\
				tests/test_pop_back.c	\
				tests/test_list_len.c

OBJ	=	$(SRC:.c=.o)

NAME	=	"liblist.a"

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -rf $(OBJ)
	rm -rf *.gcda
	rm -rf *.gcno

fclean: clean
	rm -rf ../$(NAME)
	rm -rf $(NAME)
	rm -rf unit_test

unit_test: fclean all
	gcc -o unit_test $(SRC) $(TEST_SRC) --coverage -lcriterion

test_run: unit_test
	./unit_test
	gcovr --exclude tests/

test_run_all: unit_test
	./unit_test
	gcovr --exclude tests/
	gcovr --exclude tests/ --branch

re: fclean all
