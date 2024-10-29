/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** annexe_double_s1
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int last_put(int f_int, int num, int total, int intp)
{
    int dfirst_int;
    int rdfirst_int;

    dfirst_int = dfirst_intf(num);
    rdfirst_int = dfirst_int % 10;
    my_put_nbr(f_int);
    my_putchar('.');
    if (rdfirst_int == 0 && dfirst_int >= 10) {
        my_put_nbr(0);
        total = total / 10;
    }
    my_put_nbr(total);
    my_putchar('e');
    my_putchar('+');
    if (count_int(intp) > 1)
        my_put_nbr(count_int(intp) - 1);
    else {
        my_put_nbr(0);
        my_put_nbr(0);
    }
}

int totalf(int num, int int_part, int decint, int argp)
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
