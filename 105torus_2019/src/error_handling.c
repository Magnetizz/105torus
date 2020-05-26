/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** error_handling
*/

#include "torus.h"

int error_handling_n(char *n)
{
    for (int i = 0; n[i] != '\0'; i++) {
        if (n[i] < '0' || n[i] > '9') {
            write(2, ERROR_N, strlen(ERROR_N));
            return (FAIL);
        }
    }
    return (0);
}

int error_handling(int ac, char **av)
{
    int j = 0;

    if (av[1][0] < '1' || av[1][0] > '3') {
        write(2, ERROR_OPT, strlen(ERROR_OPT));
        return (FAIL);
    }
    for (int i = 2; i != ac - 1; i++) {
        j = 0;
        while (av[i][j] != '\0') {
            if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-')
                j++;
            else {
                write(2, ERROR_COEF, strlen(ERROR_COEF));
                return (84);
            }
        }
    }
    if (error_handling_n(av[7]) == FAIL)
        return (FAIL);
    return (0);
}
