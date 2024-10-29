/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-pierre.baud
** File description:
** my_u.c
*/

int my_u(int nb)
{
    unsigned int nbr_max = 4294967295;
    unsigned nbr;

    if (nb < 0) {
        nbr = nbr_max + nb + 1;
        my_put_nbr(nbr);
        my_putchar('\n');
    }
    if (nb >= 0) {
        my_put_nbr(nb);
        my_putchar('\n');
    }
}
