/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** mini_printf
*/

#include "my_printf.h"
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
    int countarg = 0;

    boucle_printf_baseflags(list_args, i, format);
    print_pointer_call(list_args, i, format);
    countarg += print_double1(list_args, i, format);
    countarg += print_doublep_s1(list_args, i, format);
    return countarg;
}

int boucle_printf(va_list list_args, int i, const char *format)
{
    int countarg = 0;

    for (i; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            countarg += boucle_printf_flags(list_args, i, format);
            i = i + countarg + 1;
        } else
            my_putchar(format[i]);
    }
}

int my_printf(const char *format, ...)
{
    va_list list_args;
    int i = 0;
    int error = 0;
    int c = 0;

    va_start(list_args, format);
    va_end(list_args);
    va_start(list_args, format);
    c += mini_countf(format, list_args, i, c);
    va_end(list_args);
    va_start(list_args, format);
    if (error == 0)
        boucle_printf(list_args, i, format);
    va_end(list_args);
    return c;
}
