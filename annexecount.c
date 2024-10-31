/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** annexecount
*/
#include "my_printf.h"

int my_count_nbr(int nb)
{
    long nbr = nb;
    int count = 0;

    if (nbr < 0) {
        nbr = nbr * - 1;
        count++;
    }
    if (nbr >= 10) {
        count += my_count_nbr(nb / 10);
    }
    return count + 1;
}

int my_countstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
    }
    return i;
}

int my_count_o(va_list list_args, int i, const char *format)
{
    int c = 0;

    if (format[i + 1] == 'o') {
        c += my_tab_size(va_arg(list_args, unsigned int));
    }
    return c;
}
