/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_get_index.c
*/

/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** test_list_len.c
*/

#include <criterion/criterion.h>
#include "../double_link/include/double.h"
#include <string.h>

int cmp(void *data, void *data_cmp)
{
    return strcmp((char *)data, (char *)data_cmp);
}

int cmp2(void *data, void *data_cmp)
{
    return *(int *)data - *(int *)data_cmp;
}

Test(get_index, empty_list)
{
    list_t *list = NULL;

    cr_assert_eq(get_index(list, cmp, "coucou"), -1);
}

Test(get_index, little_list_int)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    int c = 0;

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    cr_assert_eq(get_index(list, cmp2, &c), 1);
    destroy_list(&list);
}

Test(get_index, list_str_compare)
{
    list_t *list = NULL;
    int a = 0;
    int b = 1;
    char *str = strdup("coucou");

    push_back(&list, &b, INT);
    push_back(&list, &a, INT);
    push_back(&list, str, STR);
    cr_assert_eq(get_index(list, cmp, "coucou"), 2);
    free(str);
    destroy_list(&list);
}

