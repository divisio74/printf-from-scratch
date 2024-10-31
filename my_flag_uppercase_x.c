/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** my_x.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int my_tab_size_uppercase_x(unsigned int nb)
{
    int remainder_o = 0;
    int size = 0;

    while (nb >= 16) {
        remainder_o = nb % 16;
        nb = nb / 16;
        size++;
    }
    size++;
    return size;
}

int my_flag_uppercase_x(unsigned int nb)
{
    int remainder = 0;
    char alpha[] = "0123456789ABCDEF";
    int count = 0;
    int i = 0;
    char *tab;
    int size = my_tab_size_uppercase_x(nb);

    tab = malloc(my_tab_size_uppercase_x(nb) * sizeof(char));
    while (nb != 0) {
        remainder = nb % 16;
        nb = nb / 16;
        tab[i] = alpha[remainder];
        i++;
        count++;
    }
    my_revstr(tab, size);
    return count;
}

int my_put_uppercase_x(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'X') {
        my_flag_uppercase_x(va_arg(list_args, unsigned int));
    }
}
