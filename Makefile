##
## EPITECH PROJECT, 2023
## lib_list
## File description:
## Makefile
##

SRC		=	double_link/src/double_link.c	\
			double_link/src/double_link2.c	\
			double_link/src/double_link3.c

TEST_SRC	=	tests/test_push_back.c				\
				tests/test_push_front.c				\
				tests/test_pop_front.c				\
				tests/test_pop_back.c				\
				tests/test_list_len.c				\
				tests/test_destroy_list.c			\
				tests/test_print_list.c				\
				tests/test_get_data_by_index.c		\
				tests/test_get_element_by_index.c	\
				tests/test_get_index.c				\
				tests/test_remove_element.c			\
				tests/test_insert_element.c			\
				tests/test_get_type_by_index.c

OBJ	=	$(SRC:.c=.o)

NAME	=	"liblist.a"

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp double_link/include/double.h ../../include

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

test_run_html: unit_test
	./unit_test
	gcovr --exclude tests/ --branch --html-details -o res_branch.html
	gcovr --exclude tests/ --html-details -o res_cover.html

re: fclean all
