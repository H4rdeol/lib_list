/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_list_len.c
*/

#include <criterion/criterion.h>
#include "../double_link/include/double.h"

Test(list_len, empty_list)
{
    list_t *list = NULL;

    cr_assert_eq(list_len(list), 0);
}

Test(list_len, list_len_1)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;

    push_back(&list, &b, INT);
    cr_assert_eq(list_len(list), 1);
    destroy_list(&list);
}

Test(push_back, list_len_3_list)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(list_len(list), 3);
    free(str);
    destroy_list(&list);
}
