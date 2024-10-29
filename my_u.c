/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** my_u.c
*/

#include "mini_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int my_put_u_nbr(unsigned int nb)
{
    unsigned int nbr = nb;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * - 1;
    }
    if (nbr >= 10) {
        my_put_u_nbr(nbr / 10);
    }
    my_putchar(nbr % 10 + 48);
}

int my_u(int nb)
{
    unsigned int nbr_max = 4294967295;
    unsigned nbr;

    if (nb < 0) {
        nbr = nbr_max + nb + 1;
        my_put_u_nbr(nbr);
    }
    if (nb >= 0) {
        my_put_nbr(nb);
    }
}

int my_put_u(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'u') {
        my_u(va_arg(list_args, unsigned int));
    }
}
