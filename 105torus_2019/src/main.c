/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** compute 4 degrees equations
*/

#include "torus.h"

coef_t *fill_coef(coef_t *c, char **av)
{
    c->a0 = atof(av[2]);
    c->a1 = atof(av[3]);
    c->a2 = atof(av[4]);
    c->a3 = atof(av[5]);
    c->a4 = atof(av[6]);
    return (c);
}

deriv_t *fill_deriv(deriv_t *d, coef_t *c)
{
    d->d0 = c->a1;
    d->d1 = 2 * c->a2;
    d->d2 = 3 * c->a3;
    d->d3 = 4 * c->a4;
    return (d);
}

int check_method(char **av)
{
    int method = atoi(av[1]);
    coef_t *c = malloc(sizeof(double) * 5);
    deriv_t *d = malloc(sizeof(double) * 4);
    int prec = atoi(av[7]) * -1;

    c = fill_coef(c, av);
    d = fill_deriv(d, c);
    switch (method) {
    case 1 : bisection_method(c, prec, 0, 1);
        break;
    case 2 : if (newton_method(c, d, prec, 0.5) == FAIL)
            return (FAIL);
        break;
    case 3 : if (secant_method(c, prec, 0, 1) == FAIL)
            return (FAIL);
        break;
    }
    free(c);
    free(d);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac == 2 && strlen(av[1]) == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help_display();
            return (SUCCESS);
        }
    if (ac != 8) {
        write(2, ERROR_NBRARG, strlen(ERROR_NBRARG));
        return (FAIL);
    }
    if (error_handling(ac, av) == FAIL)
        return (FAIL);
    if (check_method(av) == FAIL)
        return (FAIL);
    return (SUCCESS);
}
