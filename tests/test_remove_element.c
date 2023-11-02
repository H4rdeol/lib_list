/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_remove_element.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"

Test(remove_element, remove_in_empty_list_out, .init = redirect_all_std)
{
    list_t *list = NULL;

    remove_element(&list, 1);
    cr_assert_stderr_eq_str("INDEX ERROR\n");
}

Test(remove_element, remove_in_empty_list, .init = redirect_all_std)
{
    list_t *list = NULL;

    remove_element(&list, 0);
    cr_assert_stderr_eq_str("INDEX ERROR\n");
}

Test(remove_element, negative_index, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    remove_element(&list, -1);
    cr_assert_stderr_eq_str("INDEX ERROR\n");
    free(str);
    destroy_list(&list);
}

Test(remove_element, remove_mid_elem_in_list)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    remove_element(&list, 1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(*(int *)list->data, 1);
    cr_assert_str_eq((char *)list->next->data, "coucou");
    cr_assert_null(list->next->next);
    free(str);
    destroy_list(&list);
}

Test(remove_element, remove_front_elem_in_list)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    remove_element(&list, 0);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(*(int *)list->data, 2);
    cr_assert_str_eq((char *)list->next->data, "coucou");
    cr_assert_null(list->next->next);
    free(str);
    destroy_list(&list);
}

Test(remove_element, remove_last_elem_in_list)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    remove_element(&list, 2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(*(int *)list->data, 1);
    cr_assert_eq(*(int *)list->next->data, 2);
    cr_assert_null(list->next->next);
    free(str);
    destroy_list(&list);
}

Test(remove_list, remove_in_2_len_list_front)
{
    list_t *list = NULL;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    remove_element(&list, 0);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(*(int *)list->data, 1);
    cr_assert_null(list->next);
    free(str);
    destroy_list(&list);
}

Test(remove_list, remove_in_2_len_list_last)
{
    list_t *list = NULL;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    remove_element(&list, 1);
    cr_assert_eq(list_len(list), 1);
    cr_assert_str_eq((char *)list->data, "coucou");
    cr_assert_null(list->next);
    free(str);
    destroy_list(&list);
}

Test(remove_list, remove_in_1_len_list)
{
    list_t *list = NULL;
    int b = 1;

    push_back(&list, &b, INT);

    remove_element(&list, 0);
    cr_assert_null(list);
    destroy_list(&list);
}
