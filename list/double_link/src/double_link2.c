/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** lib for list
*/

#include "../include/double_list.h"

void d_insert_list(d_list_t *list, int index, void *str, enum d_type type)
{
    d_node_t *curr = list->head;
    d_node_t *tmp;

    if (index >= list->size || index < 0 || curr == NULL) {
        write(2, "Index error\n", 12);
        return;
    }
    if (index == 0) {
        d_append_list(true, str, list, type);
    } else if (index == list->size - 1){
        d_append_list(false, str, list, type);
    } else {
        for (int i = 0; i < index - 1; i++, curr = curr->next);
        tmp = curr->next;
        curr->next = d_create_node(str, curr, tmp, type);
        tmp->prec = curr->next;
    }
    list->size++;
}

void *d_get_element(d_list_t list, int index)
{
    d_node_t *curr;

    if (index >= list.size || index < -list.size) {
        write(2, "Index error\n", 12);
        return NULL;
    }
    if (index >= 0) {
        curr = list.head;
        for (int i = 0; i < index; i++, curr = curr->next);
        return curr->data;
    }
    curr = list.queue;
    for (int i = -1; i > index; i--, curr = curr->prec);
    return curr->data;
}

void d_swap_element(d_list_t *list, int index1, int index2)
{
    d_node_t *tmp1 = list->head;
    d_node_t *tmp2 = list->head;
    void *tmp_data;

    if (index1 >= list->size || index1 < 0 ||
        index2 >= list->size || index2 < 0) {
        write(2, "Index error\n", 12);
        return;
    }
    for (int i = 0; i < index1; i++, tmp1 = tmp1->next);
    for (int i = 0; i < index2; i++, tmp2 = tmp2->next);
    tmp_data = tmp1->data;
    tmp1->data = tmp2->data;
    tmp2->data = tmp_data;
}

void d_free_data(d_list_t *list, int dim)
{
    d_node_t *curr = list->head;
    int i = 0;

    if (dim == 1){
        while (curr){
            free(curr->data);
            curr = curr->next;
        }
        return;
    }
    while (curr){
        while (((char **)curr->data)[i]) {
            free(((char **)curr->data)[i]);
            i++;
        }
        i = 0;
        curr = curr->next;
    }
}

void d_free_list(d_list_t *list, void *data, int dim_of_data)
{
    if (list->head == NULL){
        write(1, "Nothing to free\n", 16);
        return;
    }
    if (dim_of_data)
        d_free_data(list, dim_of_data);
    while (list->head)
        d_remove_list(list, 0);
    if (data)
        free(data);
}
