/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** lib for list
*/

#include "../include/list.h"

void print_l_int(list_t list)
{
    node_t *curr;

    if (list.size == 0) {
        write(1, "EMPTY LIST\n", 11);
        return;
    }
    curr = list.head;
    for (; curr; curr = curr->next) {
        my_nbr_put(*(int *) curr->data);
        write(1, "\n", 1);
    }
}

void print_l_array(list_t list)
{
    node_t *curr;

    if (list.size == 0) {
        write(1, "EMPTY LIST\n", 11);
        return;
    }
    curr = list.head;
    for (; curr; curr = curr->next) {
        array_print(curr->data);
        write(1, "\n", 1);
    }
}

static int get_index_intlist(list_t list, void *data)
{
    node_t *curr = list.head;

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

static int get_index_strlist(list_t list, void *data)
{
    node_t *curr = list.head;

    if (data == NULL){
        write(2, "Null data returning -1\n", 24);
        return -1;
    } else if (list.head == NULL){
        write(2, "Empty list returning -1\n", 24);
        return -1;
    }
    for (int i = 0; curr; curr = curr->next, i++)
        if (my_cmpstr((char *)curr->data, (char *)data) == 0)
            return i;
    write(1, "Element not in list returning -1\n", 33);
    return -1;
}

int get_index(list_t list, void *data, enum type type)
{
    if (type == INT)
        return get_index_intlist(list, data);
    else
        return get_index_strlist(list, data);
}
