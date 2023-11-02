/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_get_type_by_index.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"

Test(get_type_by_index, empty_list_1, .init = redirect_all_std)
{
    list_t *list = NULL;

    cr_assert_eq(get_type_by_index(list, 0), NONE);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
}

Test(get_type_by_index, empty_list_2, .init = redirect_all_std)
{
    list_t *list = NULL;

    cr_assert_eq(get_type_by_index(list, 1), NONE);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
}

Test(get_type_by_index, empty_list_neg, .init = redirect_all_std)
{
    list_t *list = NULL;

    cr_assert_eq(get_type_by_index(list, -1), NONE);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
}

Test(get_type_by_index, list_3_elements_pos)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_type_by_index(list, 0), INT);
    cr_assert_eq(get_type_by_index(list, 1), INT);
    cr_assert_eq(get_type_by_index(list, 2), STR);
    free(str);
    destroy_list(&list);
}

Test(get_type_by_index, list_1_elements_pos)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_type_by_index(list, 1), INT);
    free(str);
    destroy_list(&list);
}

Test(get_type_by_index, list_3_elements_neg)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_type_by_index(list, 0), INT);
    cr_assert_eq(get_type_by_index(list, -1), STR);
    cr_assert_eq(get_type_by_index(list, -2), INT);
    cr_assert_eq(get_type_by_index(list, -3), INT);
    free(str);
    destroy_list(&list);
}

Test(get_type_by_index, list_1_elements_neg)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_type_by_index(list, -2), INT);
    free(str);
    destroy_list(&list);
}

Test(get_type_by_index, list_3_elements_neg_error, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_type_by_index(list, -4), NONE);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
    free(str);
    destroy_list(&list);
}

Test(get_type_by_index, list_3_elements_pos_error, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_type_by_index(list, 3), NONE);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
    free(str);
    destroy_list(&list);
}

Test(get_type_by_index, get_and_error, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, str, STR);
    push_back(&list, &a, INT);
    cr_assert_eq(get_type_by_index(list, -2), STR);
    cr_assert_eq(get_type_by_index(list, -4), NONE);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
    free(str);
    destroy_list(&list);
}
