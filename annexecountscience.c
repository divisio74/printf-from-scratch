/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** annexecountscience
*/

#include "mini_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int count_last_put(int f_int, int num, int total, int intp)
{
    int dfirst_int;
    int rdfirst_int;
    int c;

    dfirst_int = dfirst_intf(num);
    rdfirst_int = dfirst_int % 10;
    c = c + 2;
    if (rdfirst_int == 0 && dfirst_int >= 10) {
        c += my_count_nbr(0);
        total = total / 10;
    }
    c += my_count_nbr(total);
    c = c + 2;
    if (count_int(intp) > 1)
        my_put_nbr(count_int(intp) - 1);
    else {
        my_put_nbr(0);
        my_put_nbr(0);
    }
    return c;
}

int count_totalf(int num, int int_part, int decint, int argp)
{
    int argpp;
    int f_int;
    int total;

    f_int = first_intf((int)num);
    total = int_part * mcpr(10, argp);
    total = total + decint;
    total = total - f_int * mcpr(10, count_int(total) - 1);
    if ((int)num > 10) {
        argpp = count_int(total);
        while (argpp > argp) {
            argpp = argpp / 10;
        }
        total = total / mcpr(10, argpp + count_int(int_part) - 1);
    }
    return total;
}

int my_count_doublep_s(double num, int argp)
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
        total = count_totalf(num, intp, decint, argp);
        f_int = first_intf((int)num);
        count_last_put(f_int, num, total, intp);
    }
}

int count_doublep_s1(va_list list_args, int i, const char *format)
{
    char c;
    int argp;
    int countarg = 0;

    if (format[i + 3] == 'e' && format[i + 1] == '.') {
        c = format[i + 2];
        argp = c - '0';
        my_count_doublep_s(va_arg(list_args, double), argp);
        countarg += 2;
    }
    if (format[i + 1] == 'e') {
        my_count_doublep_s(va_arg(list_args, double), 6);
    }
    return countarg;
}
