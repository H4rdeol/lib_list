/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** double_link3.c
*/

#include "../include/double.h"

void *remove_element(list_t **list, int index)
{
    list_t *tmp = *list;
    void *data = NULL;

    if (index < 0 || index >= list_len(*list)) {
        write(STDERR_FILENO, "INDEX ERROR\n", 12);
        return NULL;
    }
    if (index == 0) {
        return pop_front(list);
    }
    if (index == list_len(*list) - 1) {
        return pop_back(list);
    } else {
        for (int i = 0; i < index; tmp = tmp->next)
            i++;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        data = tmp->data;
        return free(tmp), data;
    }
}

static void insert(list_t **list, void *data, enum type type, int index)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = *list;

    new->data = data;
    new->type = type;
    for (int i = 0; i < index; tmp = tmp->next)
        i++;
    new->next = tmp;
    new->prev = tmp->prev;
    tmp->prev->next = new;
    tmp->prev = new;
}

void insert_element(list_t **list, int index, void *data, enum type type)
{
    if (index < 0 || index > list_len(*list)) {
        write(STDERR_FILENO, "INDEX ERROR\n", 12);
        return;
    }
    if (index == 0) {
        push_front(list, data, type);
    } else if (index == list_len(*list)) {
        push_back(list, data, type);
    } else {
        insert(list, data, type, index);
    }
}

enum type get_type_by_index(list_t *list, int i)
{
    int index = 0;

    if (i >= list_len(list) || list == NULL) {
        write(STDERR_FILENO, "OUT OF RANGE\n", 13);
        return NONE;
    }
    if (i >= 0) {
        for (; index < i; list = list->next)
            index++;
    } else {
        if (i < -list_len(list)) {
            write(STDERR_FILENO, "OUT OF RANGE\n", 13);
            return NONE;
        }
        for (; list->next != NULL; list = list->next);
        for (; index > i + 1; list = list->prev)
            index--;
    }
    return list->type;
}
