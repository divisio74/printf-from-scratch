/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** print_double_s1
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int dfirst_intf(int nbr)
{
    if (nbr < 0) {
        nbr = -nbr;
    }
    while (nbr >= 100) {
        nbr /= 10;
    }
    return nbr;
}

int first_intf(int nbr)
{
    if (nbr < 0) {
        nbr = -nbr;
    }
    while (nbr >= 10) {
        nbr /= 10;
    }
    return nbr;
}

int count_int(int nbr)
{
    int z = 1;

    if (nbr < 0) {
        nbr = -nbr;
    }
    while (nbr >= 10) {
        nbr /= 10;
        z++;
    }
    return z;
}

int my_put_doublep_s(double num, int argp)
{
    int intp = 0;
    double dec_part = 0;
    int decint = 0;
    int f_int = 0;
    int total = 0;

    if ((int)num > 0) {
        intp = (int)num;
        dec_part = num - intp;
        dec_part = dec_part * mcpr(10, argp);
        decint = (int)dec_part;
        total = totalf(num, intp, decint, argp);
        f_int = first_intf((int)num);
        last_put(f_int, num, total, intp);
    }
    last_put2(f_int, num, argp);
}

int print_doublep_s1(va_list list_args, int i, const char *format)
{
    char c;
    int argp;
    int countarg = 0;

    if (format[i + 3] == 'e' && format[i + 1] == '.') {
        c = format[i + 2];
        argp = c - '0';
        my_put_doublep_s(va_arg(list_args, double), argp);
        countarg += 2;
    }
    if (format[i + 1] == 'e') {
        my_put_doublep_s(va_arg(list_args, double), 6);
    }
    return countarg;
}
