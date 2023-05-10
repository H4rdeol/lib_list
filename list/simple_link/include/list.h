/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** header
*/

#ifndef LIB_LIST_H
    #define LIB_LIST_H

    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdio.h>

enum type {
    INT,
    CHAR,
    STR,
    ARRAY,
    OTHER
};

typedef struct node_s{
    void *data;
    enum type type;
    struct node_s *next;
}node_t;

typedef struct list_s{
    node_t *head;
    int size;
}list_t;

/*Create node and return it:
    *data: the data to set in the node
    *next: the next node set NULL if it add in last
    type of variable
*/
node_t *create_node(void *data, node_t *next, enum type type);
/*
Initialize struct list by setting head and queue to NULL and size to zero
*/
list_t init_list(void);
/*Return the  indexed element of a list:
    list: the list at inspect
    index: the index of the element
*/
void *get_element(list_t list, int index);
/*Swap to element with their index:
    *list: the list to modified
    index1: the first element to swap
    index2: the second element to swap
*/
void swap_element(list_t *list, int index1, int index2);
/*Return the index of an element in the list (first occurrence):
    list: the list at inspect
    *data: the data to search
    *type: the type of the data in the list (char ** not implemented)
*/
int get_index(list_t list, void *data, enum type type);
/*Add an element in the list:
    is_before: append at the beginning if true else at the end
    *data: the data to add
    *list pointer to the list
    type the type of the data
*/
void append_list(bool is_before, void *data, list_t *list, enum type type);
/*Remove an element in the list with his index:
    *list pointer to the list
    index: index of the element to remove (first = 0)
*/
void remove_list(list_t *list, int index);
/*Print all element in the list of char *:
    list the list to print
*/
void print_l_str(list_t list);
/*Print all element in the list of int:
    list the list to print
*/
void print_l_int(list_t list);
/*Print all element in the list of char **:
    list the list to print
*/
void print_l_array(list_t list);
/*Insert an element in the list before or after the indexed element:
    *list pointer to the list
    index the element where insert
    data the element to insert
    type the type of the data
*/
void insert_list(list_t *list, int index, void *str, enum type type);
/*Free the element pointed by the void *:
   *list is the pointer of the list
   dimension is the nb of dimension of the data
 */
void free_data(list_t *list, int dimension);
/*Free a list and element in:
    *list: pointer on the struct list
    *pointed_data: use if you malloc a int* for fill the list
    dim_data: 0 if data in are not malloc else the nb of dimension of data
*/
void free_list(list_t *list, void *pointed_data, int dim_data);

/*Return the len of a string*/
int my_lenstr(char const *str);
/*Compare letter by letter a string*/
int my_cmpstr(char const *str1, char const *str2);
/*Write a number on the standard output*/
int my_nbr_put(int nbr);
/*Print in a terminal an array of string*/
void array_print(char **arr);

#endif //LIB_LIST_H
