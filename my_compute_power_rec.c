/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday05-pierre.baud
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec_final(int nb, int p)
{
    int i;
    int final = nb;

    for (i = 0; i <= (p - 2); i++) {
        final = final * nb;
        my_compute_power_rec(final, p - 1);
    }
    return final;
}

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 0;
    else if (p == 0)
        return 1;
    else
        my_compute_power_rec_final(nb, p);
}
