/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** header
*/

#ifndef D_LIB_LIST_H
    #define D_LIB_LIST_H

    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdio.h>

    enum d_type {
        D_INT,
        D_CHAR,
        D_STR,
        D_ARRAY,
        D_OTHER
    };

    typedef struct d_node_s{
        struct d_node_s *prec;
        void *data;
        enum d_type type;
        struct d_node_s *next;
    }d_node_t;

    typedef struct d_list_s{
        d_node_t *head;
        d_node_t *queue;
        int size;
    }d_list_t;

    /*Create node and return it:
        *data: the data to set in the node
        *prec: the precedent node set NULL if it add in first
        *next: the next node set NULL if it add in last
        type of variable
    */
    d_node_t *d_create_node(void *, d_node_t *, d_node_t *, enum d_type);
    /*
    Initialize struct list by setting head and queue to NULL and size to zero
    */
    d_list_t d_init_list(void);
    /*Return the  indexed element of a list:
        list: the list at inspect
        index: the index of the element
    */
    void *d_get_element(d_list_t list, int index);
    /*Swap to element with their index:
        *list: the list to modified
        index1: the first element to swap
        index2: the second element to swap
    */
    void d_swap_element(d_list_t *list, int index1, int index2);
    /*Return the index of an element in the list (first occurrence):
        list: the list at inspect
        *data: the data to search
        type: the type of the data in the list
    */
    int d_get_index(d_list_t list, void *data, enum d_type type);
    /*Add an element in the list:
        is_before: append at the beginning if true else at the end
        *data: the data to add
        *list pointer to the list
        type the type of the data
    */
    void d_append_list(bool, void *, d_list_t *, enum d_type);
    /*Remove an element in the list with his index:
        *list pointer to the list
        index: index of the element to remove (first = 0)
        type the type of the data
    */
    void d_remove_list(d_list_t *list, int index);
    /*Print all element in the list of char *:
        list the list to print
        head: true for print from the head, false from the tail
    */
    void d_print_l_str(d_list_t list, bool head);
    /*Print all element in the list of int:
        list the list to print
        head: true for print from the head, false from the tail
    */
    void d_print_l_int(d_list_t list, bool head);
    /*Print all element in the list of char **:
        list the list to print
        head: true for print from the head, false from the tail
    */
    void d_print_l_array(d_list_t list, bool head);
    /*Insert an element in the list at the position given:
        *list pointer to the list
        index the element where insert
        data the element to insert
        type the type of the data
    */
    void d_insert_list(d_list_t *list, int index, void *str, enum d_type type);
    /*Free the element pointed by the void *:
       *list is the pointer of the list
       dimension is the nb of dimension of the data
     */
    void d_free_data(d_list_t *list, int dimension);
    /*Free a list and element in:
        *list: pointer on the struct list
        *pointed_data: use if you malloc a int* for fill the list
        dim_data: 0 if data in are not malloc else the nb of dimension of data
    */
    void d_free_list(d_list_t *list, void *pointed_data, int dim_data);

    /*Return the len of a string*/
    int d_my_lenstr(char const *str);
    /*Compare letter by letter a string*/
    int d_my_cmpstr(char const *str1, char const *str2);
    /*Write a number on the standard output*/
    int d_my_nbr_put(int nbr);
    /*Print in a terminal an array of string*/
    void d_print_array(char **arr);

#endif //D_LIB_LIST_H
