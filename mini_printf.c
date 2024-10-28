/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** mini_printf
*/

#include "mini_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int boucle_error(va_list list_args, int i, const char *format, int error)
{
    for (i; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            error += boucle_error_flags(list_args, i, format);
            i++;
        }
    }
    return error;
}

int boucle_error_flags(va_list list_args, int i, const char *format)
{
    int error = 0;
    int error_detected = 0;
    char *list_error = "scdief %";

    for (int s = 0; format[i + 1] == list_error[s]; s++)
        error++;
    if (error == 0)
        error_detected++;
    return error_detected;
}

int boucle_printf_flags(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 's') {
        my_putstr(va_arg(list_args, const char *));
    }
    if (format[i + 1] == 'd' || format[i + 1] == 'i') {
        my_put_nbr(va_arg(list_args, int));
    }
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(list_args, int));
    }
    if (format[i + 1] == '%') {
        my_putchar(format[i]);
    }
    print_double1(list_args, i, format);
}

int boucle_printf(va_list list_args, int i, const char *format)
{
    for (i; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            boucle_printf_flags(list_args, i, format);
            i++;
        } else
            my_putchar(format[i]);
    }
}

int mini_printf(const char *format, ...)
{
    va_list list_args;
    int i = 0;
    int error = 0;
    int c;

    va_start(list_args, format);
    // error += boucle_error(list_args, i, format, error);
    va_end(list_args);
    va_start(list_args, format);
    c += mini_countf(format, list_args, i, c);
    va_end(list_args);
    va_start(list_args, format);
    if (error == 0)
        boucle_printf(list_args, i, format);
    if (error > 0)
        write(2, "84\n", 3);
        c = 0 - c;
    va_end(list_args);
    printf(" c : %i", c);
    return c;
}
