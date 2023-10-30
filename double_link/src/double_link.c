/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** double_link.c
*/

#include "../include/double.h"

void push_front(list_t **list, void *new_data, enum type type)
{
    list_t *new = malloc(sizeof(list_t));

    new->prev = NULL;
    new->data = new_data;
    new->type = type;
    new->next = *list;
    if (*list != NULL)
        (*list)->prev = new;
    *list = new;
}

void push_back(list_t **list, void *new_data, enum type type)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = *list;

    new->next = NULL;
    new->type = type;
    new->data = new_data;
    if (*list == NULL) {
        *list = new;
        new->prev = NULL;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
        new->prev = tmp;
    }
}

void *pop_front(list_t **list)
{
    void *data = NULL;
    list_t *tmp = *list;

    if (*list == NULL) {
        write(STDERR_FILENO, "EMPTY LIST\n", 11);
        return data;
    }
    data = (*list)->data;
    *list = (*list)->next;
    if (*list != NULL)
        (*list)->prev = NULL;
    free(tmp);
    return data;
}

void *pop_back(list_t **list)
{
    list_t *tmp = *list;
    void *data = NULL;

    if (*list == NULL) {
        write(STDERR_FILENO, "EMPTY LIST\n", 11);
        return data;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    if (tmp->prev) {
        tmp = tmp->prev;
        data = tmp->next->data;
        free(tmp->next);
        tmp->next = NULL;
        return data;
    } else {
        data = tmp->data;
        free(tmp);
        *list = NULL;
        return data;
    }
}

int list_len(list_t *list)
{
    int len = 0;

    for (;list != NULL; list = list->next)
        len++;
    return len;
}
