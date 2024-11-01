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

int my_flag_uppercase_x(unsigned int nb, int argp)
{
    int remainder = 0;
    char alpha[] = "0123456789ABCDEF";
    int count = 0;
    int i = 0;
    char *tab;
    int size = my_tab_size_uppercase_x(nb);
    int z = 0;

    tab = malloc(my_tab_size_uppercase_x(nb) * sizeof(char));
    while (nb != 0) {
        remainder = nb % 16;
        nb = nb / 16;
        tab[i] = alpha[remainder];
        i++;
        count++;
    }
    my_annexe_o(size, argp);
    my_revstr(tab, size, 0);
    return count;
}

int my_put_majx_boucle(va_list list_args, int i, const char *format, int argp)
{
    int etoile = 0;
    int countarg = 0;
    char c = 0;

    if (format[i + 3] == 'X' && format[i + 1] == '.') {
        c = format[i + 2];
        if (c == '*') {
            etoile = va_arg(list_args, int);
            argp = etoile;
        } else
            argp = c - '0';
        my_flag_uppercase_x(va_arg(list_args, unsigned int), argp);
        countarg += 2;
    }
    return countarg;
}

int my_put_majx(va_list list_args, int i, const char *format)
{
    int argp = 0;
    int countarg = 0;

    if (format[i + 1] == 'X') {
        my_flag_uppercase_x(va_arg(list_args, unsigned int), argp);
    }
    if (format[i + 2] == 'X' && format[i + 1] == '#') {
        my_put_nbr(0);
        my_putchar('X');
        my_flag_uppercase_x(va_arg(list_args, unsigned int), argp);
        countarg++;
    }
    countarg += my_put_majx_boucle(list_args, i, format, argp);
    return countarg;
}
