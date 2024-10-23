/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** print_double
*/

#include "mini_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int my_put_double(double num)
{
    int c;
    int int_part = (int)num;
    double dec_part = num - int_part;
    int decint_part = (int)dec_part;

    dec_part = dec_part * 1000000;
    c += put_nbr(int_part);
    if (dec_part < 0) {
        putchar('.');
        c += put_nbr(decint_part);
    }
    return c;
}

int print_double1(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'f') {
        my_put_double(va_arg(list_args, double)) - 1;
    }
}
