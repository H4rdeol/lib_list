/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_push_front.c
*/

#include <criterion/criterion.h>
#include "../double_link/include/double.h"
#include <string.h>

Test(push_front, push_front_in_empty_list)
{
    list_t *list = NULL;
    int a = 0;

    cr_assert_null(list);
    push_front(&list, &a, INT);
    cr_assert_eq(*(int *)list->data, 0);
    cr_assert_null(list->next);
    cr_assert_null(list->prev);
    destroy_list(list);
}

Test(push_front, push_front_in_1_list)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;

    push_front(&list, &b, INT);
    push_front(&list, &a, INT);
    cr_assert_eq(*(int *)list->data, 0);
    cr_assert_eq(*(int *)list->next->data, 1);
    cr_assert_null(list->prev);
    destroy_list(list);
}

Test(push_front, push_str_in_2_list)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_front(&list, &b, INT);
    push_front(&list, &a, INT);
    push_front(&list, str, STR);
    cr_assert_str_eq((char *)list->data, "coucou");
    cr_assert_eq(*(int *)list->next->data, 0);
    cr_assert_eq(*(int *)list->next->next->data, 1);
    cr_assert_eq(*(int *)list->next->next->prev->data, 0);
    free(str);
    cr_assert_null(list->prev);
    destroy_list(list);
}
