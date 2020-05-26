/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** Newton's method
*/

#include "torus.h"

int is_derivable(deriv_t *d, double x)
{
    if (compute_derivee(d, x) == 0) {
        write(2, ERROR_DIV, strlen(ERROR_DIV));
        return (FAIL);
    }
    return (SUCCESS);
}

int does_it_stop_newt(double x0, double comp_x, int prec)
{
    double small = x0 - comp_x;

    if (small < 0)
        small = small * -1;
    if (small <= pow(10, prec))
        return (1);
    return (SUCCESS);
}

double compute_newton(coef_t *c, deriv_t *d, double x0)
{
    double next_x = 0;
    double deriv = 0;
    double func = 0;

    func = compute_equation(c, x0);
    deriv = compute_derivee(d, x0);
    next_x = func / deriv;
    next_x = x0 - next_x;
    return (next_x);
}

int newton_method(coef_t *c, deriv_t *d, int prec, double x0)
{
    double x_comp = 0;

    for (int i = 1; ; i++) {
        if (is_derivable(d, x0) == FAIL)
            return (FAIL);
        if (i == 1)
            printf("x = %.1f\n", x0);
        x_comp = x0;
        x0 = compute_newton(c, d, x0);
        if (does_it_stop_newt(x0, x_comp, prec) == 1)
            break;
        printf("x = %.*f\n", -prec, x0);
        if (i == 10000)
            break;
    }
    return (SUCCESS);
}
