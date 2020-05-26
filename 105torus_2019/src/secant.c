/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** secant method
*/

#include "torus.h"

int is_dividable(coef_t *c, double x0, double x1)
{
    double sol_0 = compute_equation(c, x0);
    double sol_1 = compute_equation(c, x1);

    if (sol_1 - sol_0 == 0)
        return (FAIL);
    return (SUCCESS);
}

int does_it_stop_sec(double x0, double x1, int prec)
{
    double small = x0 - x1;

    if (small < 0)
        small = small * -1;
    if (small <= pow(10, prec))
        return (1);
    return (SUCCESS);
}

double compute_secant(coef_t *c, double x0, double x1)
{
    double sol = 0;
    double sol_0 = compute_equation(c, x0);
    double sol_1 = compute_equation(c, x1);

    sol = sol_1 * (x1 - x0);
    sol = sol / (sol_1 - sol_0);
    sol = x1 - sol;
    return (sol);
}

int secant_method(coef_t *c, int prec, double x0, double x1)
{
    if (is_dividable(c, x0, x1) == FAIL)
        return (FAIL);
    for (int i = 0; ; i++) {
        if (does_it_stop_sec(x0, x1, prec) == 1)
            break;
        if (i % 2 == 0) {
            x0 = compute_secant(c, x0, x1);
            if (i == 0)
                printf("x = %.1f\n", x0);
            else
                printf("x = %.*f\n", -prec, x0);
        } else {
            x1 = compute_secant(c, x0, x1);
            printf("x = %.*f\n", -prec, x1);
        }
        if (i == 10000)
            break;
    }
    return (SUCCESS);
}
