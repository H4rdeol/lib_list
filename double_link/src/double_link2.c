/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** double_link2.c
*/

#include "../include/double.h"

void destroy_list(list_t **list)
{
    list_t *tmp;

    while (*list) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
    *list = NULL;
}

void print_list(list_t *list, void (*print)(list_t *), bool rev)
{
    if (rev) {
        if (list == NULL)
            return;
        for (;list->next != NULL; list = list->next);
        for (;list != NULL; list = list->prev)
            print(list);
    } else {
        for (; list != NULL; list = list->next)
            print(list);
    }
}

void *get_data_by_index(list_t *list, int i)
{
    int index = 0;

    if (i >= list_len(list) || list == NULL) {
        write(STDERR_FILENO, "OUT OF RANGE\n", 13);
        return NULL;
    }
    if (i >= 0) {
        for (; index < i; list = list->next)
            index++;
    } else {
        if (i < -list_len(list)) {
            write(STDERR_FILENO, "OUT OF RANGE\n", 13);
            return NULL;
        }
        for (; list->next != NULL; list = list->next);
        for (; index > i + 1; list = list->prev)
            index--;
    }
    return list->data;
}

list_t *get_element_by_index(list_t *list, int i)
{
    int index = 0;

    if (i >= list_len(list) || list == NULL) {
        write(STDERR_FILENO, "OUT OF RANGE\n", 13);
        return NULL;
    }
    if (i >= 0) {
        for (; index < i; list = list->next)
            index++;
    } else {
        if (i < -list_len(list)) {
            write(STDERR_FILENO, "OUT OF RANGE\n", 13);
            return NULL;
        }
        for (; list->next != NULL; list = list->next);
        for (; index > i + 1; list = list->prev)
            index--;
    }
    return list;
}

int get_index(list_t *list, int (*cmp)(void *, void *), void *data_ref)
{
    int index = 0;

    for (; list != NULL; list = list->next) {
        if (cmp(list->data, data_ref) == 0)
            return index;
        index++;
    }
    return -1;
}
