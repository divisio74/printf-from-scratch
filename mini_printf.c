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

int boucle2(va_list list_args, int ie, const char *format, int error)
{
    for (ie; ie < my_strlen(format); ie++) {
        if (format[ie] == '%') {
            error += boucle_printf_error(list_args, ie, format);
            ie++;
        }
    }
    return error;
}

int boucle_printf_error(va_list list_args, int ie, const char *format)
{
    int error = 0;
    int error_detected = 0;

    if (format[ie + 1] == 's' || format[ie + 1] == 'c') {
        error++;
    }
    if (format[ie + 1] == 'd' || format[ie + 1] == 'i') {
        error++;
    }
    if (format[ie + 1] == '%' || format[ie + 1] == ' ') {
        error++;
    }
    if (error == 0) {
        error_detected++;
    }
    return error_detected;
}

static int boucle_printf(va_list list_args, int i, const char *format)
{
    int c = 0;

    if (format[i + 1] == 's') {
        c += my_putstr(va_arg(list_args, const char *)) - 1;
    }
    if (format[i + 1] == 'd' || format[i + 1] == 'i') {
        c += my_put_nbr(va_arg(list_args, int)) - 1;
    }
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(list_args, int));
    }
    if (format[i + 1] == '%') {
        my_putchar(format[i]);
    }
    
    
    
    
    return c;
}

int mini_printf(const char *format, ...)
{
    va_list list_args;
    int i = 0;
    int ie = 0;
    int c = 0;
    int error = 0;

    va_start(list_args, format);
    error += boucle2(list_args, ie, format, error);
    if (error == 1)
        write(2, "84\n", 3);
    for (i; i < my_strlen(format) && error == 0; i++) {
        if (format[i] == '%') {
            c += boucle_printf(list_args, i, format);
            i++;
        } else
            my_putchar(format[i]);
            c++;
    }
    va_end(list_args);
    printf("c : %i", c);
    return c;
}
