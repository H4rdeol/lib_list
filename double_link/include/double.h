/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** double.h
*/

#ifndef LIB_LIST_DOUBLE_H
    #define LIB_LIST_DOUBLE_H

    #include "../../list.h"

typedef struct double_linked_list {
    struct double_linked_list *prev;
    void *data;
    enum type type;
    struct double_linked_list *next;
} list_t;

void destroy_list(list_t *list);
void remove_element(list_t **list, int index);
void print_list(list_t *list, void (*print)(), bool rev);
void push_back(list_t **list, void *data, enum type type);
void push_front(list_t **list, void *data, enum type type);
void insert_element(list_t **list, int index, void *data, enum type type);
enum type get_type_by_index(list_t *list, int i);
int list_len(list_t *list);
int get_index(list_t *list, int (*cmp)(), void *data_ref);
void *get_data_by_index(list_t *list, int index);
void *pop_back(list_t **list);
void *pop_front(list_t **list);
list_t *get_element_by_index(list_t *list, int index);

#endif //LIB_LIST_DOUBLE_H
