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

int my_put_doublepb(int int_part, int decint_part, int argp, int x)
{
    int z = x;

    my_put_nbr(int_part);
    my_putchar('.');
    for (z; z > 1; z--) {
        my_put_nbr(0);
    }
    if (argp > 1) {
        my_put_nbr(decint_part);
    } else {
        my_put_nbr(decint_part % 10);
    }
}

int my_put_doublep(double num, int argp)
{
    int int_part = (int)num;
    double dec_part = num - int_part;
    int decint_part;
    double dec_partt = dec_part;
    int x = 0;

    while ((int)dec_partt < 1) {
        x++;
        dec_partt = dec_partt * 10;
    }
    if (argp > 0) {
        dec_part = dec_part * mcpr(10, argp);
        dec_part += 0.5;
    }
    decint_part = (int)dec_part;
    if (decint_part >= mcpr(10, argp)) {
        decint_part = 0;
        int_part += 1;
    }
    my_put_doublepb(int_part, decint_part, argp, x);
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
