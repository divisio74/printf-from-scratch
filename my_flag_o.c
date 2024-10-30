/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** my_o.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int my_tab_size(unsigned int nb)
{
    int remainder_o = 0;
    int size = 0;

    while (nb >= 8) {
        remainder_o = nb % 8;
        nb = nb / 8;
        size++;
    }
    size++;
    return size;
}

char *my_revstr(char *str, int size)
{
    for (int i = size; i != -1; i--) {
        my_putchar(str[i]);
    }
}

int my_o(unsigned int nb)
{
    int remainder_o = 0;
    int count = 0;
    int i = 0;
    char *tab;
    int size = my_tab_size(nb);

    tab = malloc(my_tab_size(nb) * sizeof(char));
    while (nb != 0) {
        remainder_o = nb % 8;
        nb = nb / 8;
        tab[i] = remainder_o + '0';
        i++;
        count++;
    }
    i++;
    tab[i] = nb + '0';
    my_revstr(tab, size);
    return count;
}

int my_put_o(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'o') {
        my_o(va_arg(list_args, unsigned int));
    }
}
