/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** double_link3.c
*/

#include "../include/double.h"
#include <stdio.h>

void remove_element(list_t **list, int index)
{
    list_t *tmp = *list;
    list_t *trash = *list;

    if (index == 0) {
        *list = (*list)->next;
        (*list)->prev = NULL;
        free(trash);
    } else if (index == list_len(*list) - 1) {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->prev->next = NULL;
        free(tmp);
    } else {
        for (int i = 0; tmp->next != NULL && i < index; tmp = tmp->next)
            i++;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
}

void insert_element(list_t **list, int index, void *data, enum type type)
{
    list_t *tmp = *list;
    list_t *new = malloc(sizeof(list_t));

    new->data = data;
    new->type = type;
    if (index == 0) {
        push_front(list, data, type);
    } else if (index == list_len(*list) - 1) {
        push_back(list, data, type);
    } else {
        for (int i = 0; tmp->next != NULL && i < index; tmp = tmp->next)
            i++;
        new->next = tmp;
        new->prev = tmp->prev;
        tmp->prev->next = new;
        tmp->prev = new;
    }
}

void print(void *data)
{
    printf("%d\n", *(int *)data);
}

int main(int argc, char *argv[])
{
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 7;
    list_t *list = NULL;

    push_back(&list, &a, INT);
    push_back(&list, &b, INT);
    push_back(&list, &c, INT);
    push_back(&list, &d, INT);
    print_list(list, print, false);
    printf("___________________\n");
    remove_element(&list, 0);
    print_list(list, print, false);
    printf("___________________\n");
    insert_element(&list, 1, &e, INT);
    print_list(list, print, false);
    destroy_list(list);
    return 0;
}

/*
**
** Il reste à faire le la doc, les tests
**
*/
