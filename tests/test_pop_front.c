/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_pop_front.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"

Test(pop_front, pop_front_in_empty_list, .init = redirect_all_std)
{
    list_t *list = NULL;

    cr_assert_null(pop_front(&list));
    cr_assert_stderr_eq_str("EMPTY LIST\n");
}

Test(pop_front, pop_front_in_1_list)
{
    list_t *list = NULL;
    int b = 1;

    push_back(&list, &b, INT);

    cr_assert_eq(*(int *)pop_front(&list), 1);
    cr_assert_null(list);
    destroy_list(&list);
}

Test(pop_front, pop_front_str_in_2_list)
{
    list_t *list = NULL;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    cr_assert_str_eq((char *)pop_front(&list), "coucou");
    cr_assert_null(list->prev);
    cr_assert_null(list->next);
    cr_assert_eq(*(int *)list->data, 1);
    free(str);
    destroy_list(&list);
}

