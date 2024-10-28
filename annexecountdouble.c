/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** annexecountdouble
*/
#include "mini_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int my_count_doublep(double num, int arg1)
{
    int c = 0;
    int int_part = (int)num;
    double dec_part = num - int_part;
    int decint_part = (int)dec_part;

    dec_part = dec_part * my_compute_power_rec(10, arg1);
    c += my_count_nbr(int_part);
    c++;
    c += arg1;
    return c;
}

int count_double1(va_list list_args, int i, const char *format)
{
    int c = 0;
    char c;
    int arg1;

    if (format[i + 3] == 'f' && format[i + 1] == '.') {
        c = format[i + 2];
        arg1 = c - '0';
        c += my_count_doublep(va_arg(list_args, double), arg1);
        i++;
    }
    if (format[i + 1] == 'f' || format[i + 2] == 'f') {
        c += my_count_doublep(va_arg(list_args, double), 6);
    }
    return c;
}
