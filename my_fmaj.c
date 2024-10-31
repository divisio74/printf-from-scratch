/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** my_F
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int print_double_formatmaj(va_list list_args, int i, const char *format)
{
    int etoile = 0;
    char c = 0;
    int argp = 0;
    int countarg = 0;

    if (format[i + 3] == 'F' && format[i + 1] == '.') {
        c = format[i + 2];
        if (c == '*') {
            etoile = va_arg(list_args, int);
            argp = etoile;
        } else
            argp = c - '0';
        my_put_doublep(va_arg(list_args, double), argp);
        countarg += 2;
    }
    return countarg;
}

int print_double1maj(va_list list_args, int i, const char *format)
{
    int etoile = 0;
    char c = 0;
    int argp = 0;
    int countarg = 0;

    countarg = print_double_formatmaj(list_args, i, format);
    if (format[i + 1] == 'F') {
        my_put_doublep(va_arg(list_args, double), 6);
    }
    return countarg;
}
