/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** addon for lib
*/

#include "../include/double_list.h"

int d_my_lenstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i += 1;
    }
    return i;
}

int d_my_cmpstr(char const *s1, char const *s2)
{
    int s1_value = 0;
    int s2_value = 0;

    for (int i = 0; i < d_my_lenstr(s1); i++)
        s1_value += s1[i];
    for (int j = 0; j < d_my_lenstr(s2); j++)
        s2_value += s2[j];
    return (s1_value - s2_value);
}

static void d_my_putchar(char c)
{
    write(1, &c, 1);
}

int d_my_nbr_put(int nb)
{
    int i = 1;

    if (nb >= 0){
        if (nb >= 10){
            i = nb % 10;
            nb = (nb - i) / 10;
            d_my_nbr_put(nb);
            d_my_putchar(48 + i);
        }else{
            d_my_putchar(48 + nb % 10);
        }
    } else {
        d_my_putchar('-');
        d_my_nbr_put(nb * -1);
    }
    return 0;
}

void d_print_array(char **arr)
{
    int i = 0;

    while (arr[i]) {
        write(1, arr[i], d_my_lenstr(arr[i]));
        if (arr[i + 1])
            write(1, " : ", 3);
        i++;
    }
}
