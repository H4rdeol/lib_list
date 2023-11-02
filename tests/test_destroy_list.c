/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_destroy_list.c
*/

#include <criterion/criterion.h>
#include "../double_link/include/double.h"

Test(destroy_list, empty_list)
{
    list_t *list = NULL;

    destroy_list(&list);
    cr_assert_null(list);
}

Test(destroy_list, list_3_element)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_not_null(list);
    free(str);
    destroy_list(&list);
    cr_assert_null(list);
}
