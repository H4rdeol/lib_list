/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** addon for lib
*/

#include "../include/list.h"

int my_lenstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i += 1;
    }
    return i;
}

int my_cmpstr(char const *s1, char const *s2)
{
    int s1_value = 0;
    int s2_value = 0;

    for (int i = 0; i < my_lenstr(s1); i++)
        s1_value += s1[i];
    for (int j = 0; j < my_lenstr(s2); j++)
        s2_value += s2[j];
    return (s1_value - s2_value);
}

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_nbr_put(int nb)
{
    int i = 1;

    if (nb >= 0){
        if (nb >= 10){
            i = nb % 10;
            nb = (nb - i) / 10;
            my_nbr_put(nb);
            my_putchar(48 + i);
        }else{
            my_putchar(48 + nb % 10);
        }
    } else {
        my_putchar('-');
        my_nbr_put(nb * -1);
    }
    return 0;
}

void array_print(char **arr)
{
    int i = 0;

    while (arr[i]) {
        write(1, arr[i], my_lenstr(arr[i]));
        if (arr[i + 1])
            write(1, " : ", 3);
        i++;
    }
}
