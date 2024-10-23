/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** annexe
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    long nbr = nb;
    int count = 0;

    if (nbr < 0) {
        my_putchar(45);
        nbr = nbr * - 1;
        count++;
    }
    if (nbr >= 10) {
        count += my_put_nbr(nb / 10);
    }
    my_putchar(nbr % 10 + 48);
    return count + 1;
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
    }
    return i;
}

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return i;
}
