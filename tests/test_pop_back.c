/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_pop_back.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(pop_back, pop_back_in_empty_list, .init = redirect_all_std)
{
    list_t *list = NULL;

    cr_assert_null(pop_back(&list));
    cr_assert_stderr_eq_str("EMPTY LIST\n");
}

Test(pop_back, pop_back_in_1_list)
{
    list_t *list = NULL;
    int b = 1;

    push_back(&list, &b, INT);

    cr_assert_eq(*(int *)pop_back(&list), 1);
    cr_assert_null(list);
    destroy_list(list);
}

Test(pop_back, pop_back_str_in_2_list)
{
    list_t *list = NULL;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, str, STR);

    cr_assert_str_eq((char *)pop_back(&list), "coucou");
    cr_assert_null(list->prev);
    cr_assert_null(list->next);
    cr_assert_eq(*(int *)list->data, 1);
    free(str);
    destroy_list(list);
}

