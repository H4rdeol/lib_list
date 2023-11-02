/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_print_list.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"
#include <stdio.h>

void print(list_t *list)
{
    char str[30] = {0};

    if (list->type == INT) {
        sprintf(str, "%d\n", *(int *)list->data);
        write(STDOUT_FILENO, str, strlen(str));
    } else if (list->type == STR) {
        write(STDOUT_FILENO, (char *)list->data, strlen((char *)list->data));
    }
}

Test(print_list, empty_list_not_rev, .init = redirect_all_std)
{
    list_t *list = NULL;

    print_list(list, print, false);
    cr_assert_stdout_eq_str("");
    destroy_list(&list);
}

Test(print_list, empty_list_rev, .init = redirect_all_std)
{
    list_t *list = NULL;

    print_list(list, print, true);
    cr_assert_stdout_eq_str("");
    destroy_list(&list);
}

Test(print_list, print_list_1_type_not_rev, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;

    push_front(&list, &a, INT);
    push_back(&list, &b, INT);

    print_list(list, print, false);
    cr_assert_stdout_eq_str("2\n1\n");
    destroy_list(&list);
}

Test(print_list, print_list_1_type_rev, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;

    push_front(&list, &a, INT);
    push_back(&list, &b, INT);

    print_list(list, print, true);
    cr_assert_stdout_eq_str("1\n2\n");
    destroy_list(&list);
}

Test(print_list, print_list_2_type_list_not_rev, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    int a = 0;
    char *str = strdup("coucou\n");

    push_back(&list, &a, INT);
    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    print_list(list, print, false);
    cr_assert_stdout_eq_str("coucou\n0\n1\n");
    free(str);
    destroy_list(&list);
}

Test(print_list, print_list_2_type_list_rev, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    int a = 0;
    char *str = strdup("coucou\n");

    push_back(&list, &a, INT);
    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    print_list(list, print, true);
    cr_assert_stdout_eq_str("1\n0\ncoucou\n");
    free(str);
    destroy_list(&list);
}
