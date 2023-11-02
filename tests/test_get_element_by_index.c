/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_get_element_by_index.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"

Test(get_element_by_index, empty_list_1, .init = redirect_all_std)
{
    list_t *list = NULL;

    get_element_by_index(list, 0);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
}

Test(get_element_by_index, empty_list_2, .init = redirect_all_std)
{
    list_t *list = NULL;

    get_element_by_index(list, 1);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
}

Test(get_element_by_index, empty_list_neg, .init = redirect_all_std)
{
    list_t *list = NULL;

    cr_assert_null(get_element_by_index(list, -1));
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
}

Test(get_element_by_index, list_3_elements_pos)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(*(int *)(get_element_by_index(list, 0)->data), 1);
    cr_assert_eq((get_element_by_index(list, 0)->type), INT);
    cr_assert_eq(*(int *)(get_element_by_index(list, 0)->next->data), 0);
    cr_assert_null(get_element_by_index(list, 0)->prev);
    cr_assert_eq(*(int *)(get_element_by_index(list, 1)->data), 0);
    cr_assert_str_eq((char *)(get_element_by_index(list, 2)->data), "coucou");
    free(str);
    destroy_list(&list);
}

Test(get_element_by_index, list_1_elements_pos)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(*(int *)(get_element_by_index(list, 1)->data), 1);
    cr_assert_eq((get_element_by_index(list, 1)->type), INT);
    cr_assert_eq(*(int *)(get_element_by_index(list, 1)->prev->data), 0);
    cr_assert_str_eq((char *)(
        get_element_by_index(list, 1)->next->data),
        "coucou"
    );
    free(str);
    destroy_list(&list);
}

Test(get_element_by_index, list_3_elements_neg)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(*(int *)(get_element_by_index(list, 0)->data), 1);
    cr_assert_str_eq((char *)(get_element_by_index(list, -1)->data), "coucou");
    cr_assert_eq((get_element_by_index(list, -1)->type), STR);
    cr_assert_null(get_element_by_index(list, -1)->next);
    cr_assert_eq(*(int *)(get_element_by_index(list, -1)->prev->data), 0);
    cr_assert_eq(*(int *)(get_element_by_index(list, -2)->data), 0);
    cr_assert_eq(*(int *)(get_element_by_index(list, -3)->data), 1);
    free(str);
    destroy_list(&list);
}

Test(get_element_by_index, list_1_elements_neg)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(*(int *)(get_element_by_index(list, -2)->data), 0);
    cr_assert_eq((get_element_by_index(list, -2)->type), INT);
    cr_assert_str_eq(
        (char *)(get_element_by_index(list, -2)->next->data),
        "coucou"
    );
    cr_assert_eq(*(int *)(get_element_by_index(list, -2)->prev->data), 1);
    free(str);
    destroy_list(&list);
}

Test(get_element_by_index, list_3_elements_neg_error, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    get_element_by_index(list, -4);
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
    free(str);
    destroy_list(&list);
}

Test(get_element_by_index, list_3_elements_pos_error, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_null(get_element_by_index(list, 3));
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
    free(str);
    destroy_list(&list);
}

Test(get_element_by_index, get_and_error, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, str, STR);
    push_back(&list, &a, INT);
    cr_assert_str_eq((char *)(get_element_by_index(list, -2)->data), "coucou");
    cr_assert_null(get_data_by_index(list, -4));
    cr_assert_stderr_eq_str("OUT OF RANGE\n");
    free(str);
    destroy_list(&list);
}
