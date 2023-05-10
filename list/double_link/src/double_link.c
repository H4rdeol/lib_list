/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** function for double linked list
*/

#include "../include/double_list.h"

d_list_t d_init_list(void)
{
    d_list_t new;
    new.size = 0;
    new.head = NULL;
    new.queue = NULL;
    return new;
}

d_node_t *d_create_node(void *d, d_node_t *p, d_node_t *next, enum d_type type)
{
    d_node_t *new = malloc(sizeof(d_node_t));
    new->prec = p;
    new->data = d;
    new->next = next;
    new->type = type;
    return new;
}

void d_append_list(bool is_before, void *data, d_list_t *list, enum d_type type)
{
    if (list->size == 0) {
        list->head = d_create_node(data, NULL, NULL, type);
        list->queue = list->head;
        list->size++;
        return;
    }
    if (is_before){
        d_node_t *new = d_create_node(data, NULL, list->head, type);
        list->head->prec = new;
        list->head = new;
    } else {
        d_node_t *new = d_create_node(data, list->queue, NULL, type);
        list->queue->next = new;
        list->queue = new;
    }
    list->size++;
}

void d_remove_list(d_list_t *list, int index)
{
    d_node_t *curr = list->head;
    d_node_t *tmp = list->head;

    (list->size == 1) ? list->head = NULL : (0);
    if (index == 0 && list->head) {
        list->head = list->head->next;
        list->head->prec = NULL; list->size--; free(tmp); return;
    }
    if (index == list->size - 1 && list->head) {
        tmp = list->queue;
        list->queue = list->queue->prec;
        list->queue->next = NULL;
    }
    if (list->head) {
        for (int i = 0; i < index - 1; i++, curr = curr->next);
        tmp = curr->next;
        curr->next = tmp->next;
        curr = curr->next;
        curr->prec = tmp->prec;
    } free(tmp); list->size--;
}

void d_print_l_str(d_list_t list, bool dir)
{
    d_node_t *curr;

    if (list.size == 0) {
        write(1, "EMPTY LIST\n", 11);
        return;
    }
    if (dir) {
        curr = list.head;
        for (; curr; curr = curr->next) {
            write(1, (char *)curr->data, d_my_lenstr((char *)curr->data));
            write(1, "\n", 1);
        }
    }else{
        curr = list.queue;
        for (; curr; curr = curr->prec) {
            write(1, (char *)curr->data, d_my_lenstr((char *)curr->data));
            write(1, "\n", 1);
        }
    }
}
