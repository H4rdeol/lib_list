/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_push_back.c
*/

#include <criterion/criterion.h>
#include "../double_link/include/double.h"
#include <string.h>

Test(push_back, push_back_in_empty_list)
{
    list_t *list = NULL;
    int a = 0;

    cr_assert_null(list);
    push_back(&list, &a, INT);
    cr_assert_eq(*(int *)list->data, 0);
    cr_assert_null(list->next);
    cr_assert_null(list->prev);
    destroy_list(list);
}

Test(push_back, push_back_in_1_list)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    cr_assert_eq(*(int *)list->data, 1);
    cr_assert_eq(*(int *)list->next->data, 0);
    cr_assert_null(list->prev);
    cr_assert_null(list->next->next);
    destroy_list(list);
}

Test(push_back, push_back_str_in_2_list)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_str_eq((char *)list->next->next->data, "coucou");
    cr_assert_eq(*(int *)list->next->data, 0);
    cr_assert_eq(*(int *)list->next->next->prev->data, 0);
    free(str);
    cr_assert_null(list->prev);
    cr_assert_null(list->next->next->next);
    destroy_list(list);
}
