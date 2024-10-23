/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-pierre.baud
** File description:
** main
*/

#include <stdio.h>
#include "mini_printf.h"

int main(void)
{
    char *str = "epitech";
    int i = 7;

    mini_printf("The word %%%s%% has %i characters .\n", str , i);
}
