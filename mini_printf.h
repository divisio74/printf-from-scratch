/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MINI_PRINTF_H
    #define MINI_PRINTF_H

int my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(const char *str);
int my_putstr(const char *str);
int mini_printf(const char *format, ...);
int my_count_nbr(int nb);
int my_countstr(char const *str);
int my_count_double(double num);
int count_double1(va_list list_args, int i, const char *format);
int mini_countf(const char *format, va_list list_args, int i, int c);
int boucle_countf(va_list list_args, int i, const char *format);
int boucle_error(va_list list_args, int i, const char *format, int error);
int boucle_error_flags(va_list list_args, int i, const char *format);
int boucle_printf_flags(va_list list_args, int i, const char *format);
int my_count_doublep(double num, int arg1);
int print_double1(va_list list_args, int i, const char *format);
int mcpr(int nb, int p);
int mcpr_final(int nb, int p);
int my_put_doublep_s(double num, int argp);
int print_doublep_s1(va_list list_args, int i, const char *format);
int last_put(int first_int, int num, int total, int int_part);
int totalf(int num, int int_part, int decint, int argp);
int dfirst_intf(int nbr);
int first_intf(int nbr);
int count_int(int nbr);
int my_u(int nb);
int my_put_u(va_list list_args, int i, const char *format);

#endif
