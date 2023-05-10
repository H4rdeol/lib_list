/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** lib for list
*/

#include "../include/double_list.h"

void d_print_l_int(d_list_t list, bool dir)
{
    d_node_t *curr;

    if (list.size == 0) {
        write(1, "EMPTY LIST\n", 11);
        return;
    }
    if (dir) {
        curr = list.head;
        for (; curr; curr = curr->next) {
            d_my_nbr_put(*(int *)curr->data);
            write(1, "\n", 1);
        }
    }else{
        curr = list.queue;
        for (; curr; curr = curr->prec) {
            d_my_nbr_put(*(int *)curr->data);
            write(1, "\n", 1);
        }
    }
}

void d_print_l_array(d_list_t list, bool dir)
{
    d_node_t *curr;

    if (list.size == 0) {
        write(1, "EMPTY LIST\n", 11);
        return;
    }
    if (dir) {
        curr = list.head;
        for (; curr; curr = curr->next) {
            d_print_array(curr->data);
            write(1, "\n", 1);
        }
    }else{
        curr = list.queue;
        for (; curr; curr = curr->prec) {
            d_print_array(curr->data);
            write(1, "\n", 1);
        }
    }
}

static int d_get_index_intlist(d_list_t list, void *data)
{
    d_node_t *curr = list.head;

    if (data == NULL){
        write(2, "Null data returning -1\n", 24);
        return -1;
    } else if (list.head == NULL){
        write(2, "Empty list returning -1\n", 24);
        return -1;
    }
    for (int i = 0; curr; curr = curr->next, i++)
        if (*(int *)data == *(int *)curr->data)
            return i;
    write(1, "Element not in list returning -1\n", 33);
    return -1;
}

static int d_get_index_strlist(d_list_t list, void *data)
{
    d_node_t *curr = list.head;

    if (data == NULL){
        write(2, "Null data returning -1\n", 24);
        return -1;
    } else if (list.head == NULL){
        write(2, "Empty list returning -1\n", 24);
        return -1;
    }
    for (int i = 0; curr; curr = curr->next, i++)
        if (d_my_cmpstr((char *)curr->data, (char *)data) == 0)
            return i;
    write(1, "Element not in list returning -1\n", 33);
    return -1;
}

int d_get_index(d_list_t list, void *data, enum d_type type)
{
    if (type == D_INT)
        return d_get_index_intlist(list, data);
    else
        return d_get_index_strlist(list, data);
}
