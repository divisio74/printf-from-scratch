/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** annexe_flags
*/
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int my_put_nbrp(int nb, int argp)
{
    int z = 0;

    if (argp > my_count_nbr(nb)) {
        for (z = argp - my_count_nbr(nb); z > 0; z--)
            my_put_nbr(0);
    }
    my_put_nbr(nb);
}

int my_put_str_boucle(va_list list_args, int i, const char *format)
{
    int etoile = 0;
    int countarg = 0;
    char c = 0;
    int argp = 0;

    if (format[i + 1] == 's') {
        my_putstr(va_arg(list_args, const char *), argp);
    }
    if (format[i + 3] == 's' && format[i + 1] == '.') {
        c = format[i + 2];
        if (c == '*') {
            etoile = va_arg(list_args, int);
            argp = etoile;
        } else
            argp = c - '0';
        my_putstr(va_arg(list_args, const char *), argp);
        countarg += 2;
    }
    return countarg;
}

int my_put_d_boucle(va_list list_args, int i, const char *format)
{
    int etoile = 0;
    int countarg = 0;
    char c = 0;
    int argp = 0;

    if (format[i + 3] == 'd' && format[i + 1] == '.') {
        c = format[i + 2];
        if (c == '*') {
            etoile = va_arg(list_args, int);
            argp = etoile;
        } else
            argp = c - '0';
        my_put_nbrp(va_arg(list_args, int), argp);
        countarg += 2;
    }
    return countarg;
}

int my_put_di_boucle(va_list list_args, int i, const char *format)
{
    int etoile = 0;
    int countarg = 0;
    char c = 0;
    int argp = 0;

    if (format[i + 1] == 'd' || format[i + 1] == 'i') {
        my_put_nbr(va_arg(list_args, int));
    }
    if (format[i + 3] == 'i' && format[i + 1] == '.') {
        c = format[i + 2];
        if (c == '*') {
            etoile = va_arg(list_args, int);
            argp = etoile;
        } else
            argp = c - '0';
        my_put_nbrp(va_arg(list_args, int), argp);
        countarg += 2;
    }
    countarg += my_put_d_boucle(list_args, i, format);
    return countarg;
}

int boucle_printf_baseflags(va_list list_args, int i, const char *format)
{
    int countarg = 0;

    countarg += my_put_di_boucle(list_args, i, format);
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(list_args, int));
    }
    if (format[i + 1] == '%') {
        i++;
        my_putchar(format[i]);
    }
    my_put_u(list_args, i, format);
    countarg += my_put_str_boucle(list_args, i, format);
    countarg += my_put_o(list_args, i, format);
    countarg += my_put_x(list_args, i, format);
    countarg += my_put_majx(list_args, i, format);
    return countarg;
}
