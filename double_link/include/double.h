/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** double.h
*/

#ifndef LIB_LIST_DOUBLE_H
    #define LIB_LIST_DOUBLE_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>

/*!
 * \enum type
 * \brief Constant of type
 * \version 2.0v
 *
 * type is useful to know the type of data in a node if it is a common type.
*/
enum type {
    INT, /*!< Data is an int */
    STR, /*!< Data is a array of char */
    CHAR, /*!< Data is a char */
    OTHER, /*!< The type of the data is too specific */
    NONE = -1 /*!< Use it juste for error case */
};

/*!
 * \struct list_t
 * \brief Node of the list
 * \version 2.0v
 *
 *  Structure implementation for double linked list with generic data.
 *  The last element point to NULL in next and the first to in prev.
*/
typedef struct double_linked_list {
    struct double_linked_list *prev; /*!< Point to the previous element. */
    void *data; /*!< Point on a data of any type. */
    enum type type; /*!< Give the type of data if it is common. */
    struct double_linked_list *next; /*!< Point to the next element. */
} list_t;

/*!
 * \fn void destroy_list(list_t **list)
 * \brief Free all the list element.
 *
 * \param list is the list to destroy.
*/
void destroy_list(list_t **list);
/*!
 *  \fn void remove_element(list_t **list, int index)
 *  \brief Find the element at the index given in parameter and
 *      remove it from the list and free it.
 *  \version 2.0v
 *
 *  \param list the address of the head of the list
 *  \param index the index of the element to remove
*/
void *remove_element(list_t **list, int index);
/*!
 *  \fn void print_list(list_t *list, void (*print)(list_t *), bool rev)
 *  \brief Print all element in your list.
 *  \version 2.0v
 *
 *  \param list is the head of your list.
 *  \param print() is the function to use for print the data (void *) in
 *     your nodes (the function take an entire node).
 *  \param rev false for print from the head and true from the queue.
*/
void print_list(list_t *list, void (*print)(list_t *), bool rev);
/*!
 * \fn void push_back(list_t *list, void *data, enum type type)
 * \brief Add a node at the end of the list given. (Useful for queue).
 * \version 2.0v
 *
 * \param list is the pointer on the head of your list.
 * \param data is the generic pointer to the data.
 * \param type is the type of data (INT, STR, CHAR, OTHER and NONE for error).
*/
void push_back(list_t **list, void *data, enum type type);
/*!
 * \fn void push_front(list_t **list, void *data, enum type type)
 * \brief Add a node at the beginning of the list given. (Useful for stack)
 * \version 2.0v
 *
 * \param list is the pointer on the head of your list.
 * \param data is the generic pointer to the data.
 * \param type is the type of data(INT, STR, CHAR, OTHER and NONE for error).
*/
void push_front(list_t **list, void *data, enum type type);
/*!
 * \fn void insert_element(list_t **list, int i, void *data, enum type type)
 * \brief Add a node at the index given of the list pass in parameter.
 * \version 2.0v
 *
 * \param index is the index of the new element.
 * \param list is the pointer on the head of your list.
 * \param data is the generic pointer to the data.
 * \param type is the type of data (INT, STR, CHAR, OTHER and NONE for error).
*/
void insert_element(list_t **list, int index, void *data, enum type type);
/*!
 * \fn enum type get_type_by_index(list_t *list, int i)
 * \brief Give the type of data in the node at index position.
 * \version 2.0v
 *
 * \param i is the index of the element to get the type.
 * \param list is the head of your list.
*/
enum type get_type_by_index(list_t *list, int i);
/*!
 * \fn int list_len(list_t *list)
 * \brief Return the number of node in a list.
 * \version 2.0v
 *
 * \param list is the head of your list.
*/
int list_len(list_t *list);
/*!
 * \fn int get_index(list_t *list, int (*cmp)(void *, void *), void *data_ref)
 * \brief Return the index of the first element equal to data_ref.
 * \version 2.0v
 *
 * \param list is the head of your list.
 * \param cmp the function to compare data.
 * \param data_ref data reference for compare.
*/
int get_index(list_t *list, int (*cmp)(void *, void *), void *data_ref);
/*!
 * \fn void *get_data_by_index(list_t *list, int index);
 * \brief Give the data in the node at index position.
 * \version 2.0v
 *
 * \param list is the head of your list.
 * \param index is the index of the element to get the data.
*/
void *get_data_by_index(list_t *list, int index);
/*!
 * \fn void *pop_back(list_t **list)
 * \brief Remove the last node of the list and return the data.
 * \version 2.0v
 *
 * \param list the address of the head of your list.
*/
void *pop_back(list_t **list);
/*!
 * \fn void *pop_front(list_t **list)
 * \brief Remove the first node of the list and return the data.
 * \version 2.0v
 *
 * \param list the address of the head of your list.
*/
void *pop_front(list_t **list);
/*!
 * \fn list_t *get_element_by_index(list_t *list, int index);
 * \brief Give the node at index position.
 * \version 2.0v
 *
 * \param list is the head of your list.
 * \param index is the index of the element to get.
*/
list_t *get_element_by_index(list_t *list, int index);

#endif //LIB_LIST_DOUBLE_H
