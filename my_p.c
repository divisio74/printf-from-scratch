/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** test_my_p
*/

#include <stdint.h>
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>

int print_pointer_put(int x, unsigned long address, char pointeur[20])
{
    int j = 0;

    x += sizeof(address) * 2 - 4;
    for (j; j < x; j++) {
        my_putchar(pointeur[j]);
    }
}

int print_pointer_call(va_list list_args, int i, const char *format)
{
    if (format[i + 1] == 'p')
        print_pointer(va_arg(list_args, void *));
}

int print_pointer(void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    char pointeur[20];
    int x = 0;
    unsigned long adresstemp = address;
    unsigned long digit = 0;

    pointeur[x] = '0';
    x++;
    pointeur[x] = 'x';
    x++;
    for (int i = sizeof(address) * 2 - 5; i >= 0; i--) {
        digit = adresstemp % 16;
        adresstemp /= 16;
        if (digit < 10) {
            pointeur[x + i] = '0' + digit;
        } else {
            pointeur[x + i] = 'a' + (digit - 10);
        }
    }
    print_pointer_put(x, address, pointeur);
}
