/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** my_x.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int my_tab_size_x(unsigned int nb)
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

int my_x(unsigned int nb)
{
    int remainder_x = 0;
    char alpha[] = "0123456789abcdef";
    int count = 0;
    int i = 0;
    char *tab;
    int size = my_tab_size_x(nb);
    int argp = 0;

    tab = malloc(my_tab_size_x(nb) * sizeof(char));
    while (nb != 0) {
        remainder_x = nb % 16;
        nb = nb / 16;
        tab[i] = alpha[remainder_x];
        i++;
        count++;
    }
    my_revstr(tab, size, argp);
    return count;
}

int my_put_x(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'x') {
        my_x(va_arg(list_args, unsigned int));
    }
}
