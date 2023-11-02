/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_insert_element.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../double_link/include/double.h"
#include "test.h"

Test(insert_element, insert_in_empty_list_out, .init = redirect_all_std)
{
    list_t *list = NULL;
    int a = 0;

    insert_element(&list, 1, &a, INT);
    cr_assert_stderr_eq_str("INDEX ERROR\n");
}

Test(insert_element, insert_in_empty_list)
{
    list_t *list = NULL;
    int a = 0;

    insert_element(&list, 0, &a, INT);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(*(int *)list->data, 0);
    cr_assert_null(list->next);
    cr_assert_null(list->prev);
    destroy_list(&list);
}

Test(insert_element, insert_out_elem_in_list, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    insert_element(&list, 4, &c, INT);
    cr_assert_stderr_eq_str("INDEX ERROR\n");
    free(str);
    destroy_list(&list);
}

Test(insert_element, negative_index, .init = redirect_all_std)
{
    list_t *list = NULL;
    int b = 1;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    insert_element(&list, -1, &c, INT);
    cr_assert_stderr_eq_str("INDEX ERROR\n");
    free(str);
    destroy_list(&list);
}

Test(insert_element, insert_mid_elem_in_list)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    insert_element(&list, 1, &c, INT);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(*(int *)list->next->data, 9);
    cr_assert_eq(*(int *)list->next->prev->data, 1);
    cr_assert_eq(*(int *)list->next->next->data, 2);
    free(str);
    destroy_list(&list);
}

Test(insert_element, insert_front_elem_in_list)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    insert_element(&list, 0, &c, INT);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(*(int *)list->data, 9);
    cr_assert_not_null(list->next);
    cr_assert_eq(*(int *)list->next->data, 1);
    cr_assert_null(list->prev);
    free(str);
    destroy_list(&list);
}

Test(insert_element, insert_last_elem_in_list)
{
    list_t *list = NULL;
    int b = 1;
    int a = 2;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);

    insert_element(&list, 3, &c, INT);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(*(int *)list->next->next->next->data, 9);
    cr_assert_str_eq((char *)list->next->next->next->prev->data, "coucou");
    cr_assert_null(list->next->next->next->next);
    free(str);
    destroy_list(&list);
}

Test(insert_list, insert_in_2_len_list_front)
{
    list_t *list = NULL;
    int b = 1;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    insert_element(&list, 0, &c, INT);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(*(int *)list->data, 9);
    cr_assert_str_eq((char *)list->next->data, "coucou");
    cr_assert_not_null(list->next);
    cr_assert_null(list->prev);
    free(str);
    destroy_list(&list);
}

Test(insert_list, insert_in_2_len_list_last)
{
    list_t *list = NULL;
    int b = 1;
    int c = 9;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_front(&list, str, STR);

    insert_element(&list, 2, &c, INT);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(*(int *)list->next->next->data, 9);
    cr_assert_eq(*(int *)list->next->next->prev->data, 1);
    cr_assert_null(list->next->next->next);
    free(str);
    destroy_list(&list);
}

Test(insert_list, insert_in_1_len_list)
{
    list_t *list = NULL;
    int b = 1;
    int c = 9;
    push_back(&list, &b, INT);

    insert_element(&list, 0, &c, INT);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(*(int *)list->next->data, 1);
    cr_assert_eq(*(int *)list->data, 9);
    cr_assert_null(list->next->next);
    destroy_list(&list);
}
