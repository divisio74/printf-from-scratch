/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** annexe_o
*/
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int my_annexe_o(int size, int argp)
{
    int z = 0;

    if (argp > size) {
        for (z = argp - size; z > 0; z--) {
            my_put_nbr(0);
        }
    }
}
