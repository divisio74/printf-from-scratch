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

int my_hexa_letter(unsigned int remainder)
{
    int letter_x;

    if (remainder >= 10) {
        letter_x = remainder + 87;
        return letter_x;
    } else {
        return remainder + '0';
    }
}

int my_x(unsigned int nb)
{
    int remainder_x;
    int count;
    char *tab;
    int i = 0;
    int size = my_tab_size_x(nb);

    tab = malloc(my_tab_size_x(nb) * sizeof(char));
    while (nb >= 16) {
        remainder_x = nb % 16;
        nb = nb / 16;
        tab[i] = my_hexa_letter(remainder_x);
        i++;
    }
    remainder_x = nb;
    i++;
    tab[i] = my_hexa_letter(remainder_x);
    my_revstr(tab, size);
    return count;
}

int my_put_x(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'x') {
        my_x(va_arg(list_args, unsigned int));
    }
}
