/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** print_double
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int mcpr_final(int nb, int p)
{
    int i;
    int final = nb;

    for (i = 0; i <= (p - 2); i++) {
        final = final * nb;
        mcpr(final, p - 1);
    }
    return final;
}

int mcpr(int nb, int p)
{
    if (p < 0)
        return 0;
    else if (p == 0)
        return 1;
    else
        mcpr_final(nb, p);
}

int my_put_doublep(double num, int argp)
{
    int int_part = (int)num;
    double dec_part = num - int_part;
    int decint_part;

    dec_part = dec_part * mcpr(10, argp);
    decint_part = (int)dec_part;
    my_put_nbr(int_part);
    my_putchar('.');
    my_put_nbr(decint_part);
}

int print_double1(va_list list_args, int i, const char *format)
{
    char c = 0;
    int argp = 0;
    int countarg = 0;

    if (format[i + 3] == 'f' && format[i + 1] == '.') {
        c = format[i + 2];
        argp = c - '0';
        my_put_doublep(va_arg(list_args, double), argp);
        countarg += 2;
    }
    if (format[i + 1] == 'f') {
        my_put_doublep(va_arg(list_args, double), 6);
    }
    return countarg;
}
