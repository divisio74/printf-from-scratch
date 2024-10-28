/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** mini_count
*/

#include "mini_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int boucle_countf(va_list list_args, int i, const char *format)
{
    int c = 0;

    if (format[i + 1] == 's') {
        c += my_countstr(va_arg(list_args, const char *));
    }
    if (format[i + 1] == 'd' || format[i + 1] == 'i') {
        c += my_count_nbr(va_arg(list_args, int));
    }
    if (format[i + 1] == 'c') {
        c++;
    }
    if (format[i + 1] == '%') {
        c++;
    }
    c += count_double1(list_args, i, format);
    if (count_double1 > 0)
        i += 3;
    return c;
}

int mini_countf(const char *format, va_list list_args, int i, int c)
{
    for (i; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            c += boucle_countf(list_args, i, format);
            i++;
        } else
            c++;
    }
    va_end(list_args);
    return c;
}
