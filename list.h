/*
** EPITECH PROJECT, 2023
** lib_list
** File description:
** list.h
*/

#ifndef LIB_LIST_LIST_H
    #define LIB_LIST_LIST_H

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

#endif //LIB_LIST_LIST_H
