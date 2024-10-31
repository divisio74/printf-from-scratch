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

char *my_revstr(char *str, int size, int argp)
{
    if (argp > 0) {
        for (int i = size - 1; i != - 1 && argp > 0; i--) {
            my_putchar(str[i]);
            argp--;
        }
    } else {
        for (int i = size - 1; i != -1; i--) {
            my_putchar(str[i]);
        }
    }
}

int my_o(unsigned int nb, int argp)
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
    my_revstr(tab, size, argp);
    return count;
}

int my_put_o_boucle(va_list list_args, int i, const char *format, int argp)
{
    int etoile = 0;
    int countarg = 0;
    char c = 0;

    if (format[i + 3] == 'o' && format[i + 1] == '.') {
        c = format[i + 2];
        if (c == '*') {
            etoile = va_arg(list_args, int);
            argp = etoile;
        } else
            argp = c - '0';
        my_o(va_arg(list_args, unsigned int), argp);
        countarg += 2;
    }
    return countarg;
}

int my_put_o(va_list list_args, int i, const char *format)
{
    int argp = 0;
    int countarg = 0;

    if (format[i + 1] == 'o') {
        my_o(va_arg(list_args, unsigned int), argp);
    }
    if (format[i + 2] == 'o' && format[i + 1] == '#') {
        my_put_nbr(0);
        my_o(va_arg(list_args, unsigned int), argp);
        countarg++;
    }
    countarg += my_put_o_boucle(list_args, i, format, argp);
    return countarg;
}
