/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** function for double linked list
*/

#include "../include/list.h"

list_t init_list(void)
{
    list_t new;
    new.size = 0;
    new.head = NULL;
    return new;
}

node_t *create_node(void *data, node_t *next, enum type type)
{
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = next;
    new->type = type;
    return new;
}

void append_list(bool is_before, void *data, list_t *list, enum type type)
{
    if (list->size == 0) {
        list->head = create_node(data, NULL, type);
        list->size++;
        return;
    }
    if (is_before){
        list->head = create_node(data, list->head, type);
    } else {
        node_t *curr = list->head;
        for (;curr->next; curr = curr->next);
        curr->next = create_node(data, NULL, type);
    }
    list->size++;
}

void remove_list(list_t *list, int index)
{
    node_t *curr, *trash;

    if (index >= list->size || index < 0) {
        write(2, "Index error\n", 12); return;
    }else if (list->size == 1) {
        free(list->head); list->head = NULL; list->size = 0; return;
    }
    if (index == 0){
        trash = list->head; list->head = list->head->next;
        free(trash); list->size--; return;
    }
    if (index == list->size - 1){
        curr = list->head;
        for (int i = 0; i < index - 1; i++, curr = curr->next);
        trash = curr->next; curr->next = NULL; free(trash);
    }else {
        curr = list->head;
        for (int i = 0; i < index - 1; i++, curr = curr->next);
        trash = curr->next; curr->next = trash->next; free(trash);
    } list->size--;
}

void print_l_str(list_t list)
{
    node_t *curr;

    if (list.size == 0) {
        write(1, "EMPTY LIST\n", 11);
        return;
    }
    curr = list.head;
    for (; curr; curr = curr->next) {
        write(1, (char *)curr->data, my_lenstr((char *)curr->data));
        write(1, "\n", 1);
    }
}
