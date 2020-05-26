/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** compute equations and derived functions
*/

#include  "torus.h"

double compute_derivee(deriv_t *d, double x)
{
    double sol = 0;

    sol = (d->d3 * pow(x, 3)) + (d->d2 * pow(x, 2));
    sol += (d->d1 * x) + d->d0;
    return (sol);
}

double compute_equation(coef_t *co, double x)
{
    double sol = 0;

    sol = (co->a4 * pow(x, 4)) + (co->a3 * pow(x, 3));
    sol += (co->a2 * pow(x, 2)) + (co->a1 * x) + co->a0;
    return (sol);
}
