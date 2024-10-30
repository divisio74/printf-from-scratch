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

int boucle_printf_baseflags(va_list list_args, int i, const char *format)
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
        i++;
        my_putchar(format[i]);
    }
    my_put_u(list_args, i, format);
    my_put_o(list_args, i, format);
    my_put_x(list_args, i, format);
    my_put_uppercase_x(list_args, i, format);
}
