/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** bisection method
*/

#include "torus.h"

int does_it_stop(double sol, int prec)
{
    if (sol < 0)
        sol = sol * -1;
    if (sol == 0 || sol <= pow(10, prec))
        return (1);
    return (SUCCESS);
}

float check_a_b_cases(coef_t *co, double a, double b)
{
    double sol = 0;

    sol = compute_equation(co, a);
    if (sol == 0) {
        printf("x = %.0f\n", a);
        return (sol);
    }
    sol = compute_equation(co, b);
    if (sol == 0)
        printf("x = %.0f\n", b);
    return (sol);
}

void bisection_computing(coef_t *co, int prec, double a, double b)
{
    int dis_p = 1;
    double sol_c = 0;
    double sol_a = 0;
    int j = 1;

    for (double c = (a + b) / 2; dis_p != (prec * -1) + 2; dis_p++, j++) {
        if (dis_p == (prec * -1) + 1)
            dis_p--;
        sol_c = compute_equation(co, c);
        printf("x = %.*f\n", dis_p, c);
        sol_a = compute_equation(co, a);
        if (does_it_stop(sol_c, prec) == 1)
            break;
        if (sol_a * sol_c != 0) {
            if (sol_a * sol_c > 0)
                a = c;
            if (sol_a * sol_c < 0)
                b = c;
        }
        if (j == 10000)
            break;
        c = (a + b) / 2;
    }
}

int bisection_method(coef_t *co, int prec, double a, double b)
{
    if (check_a_b_cases(co, a, b) == SUCCESS)
        return (SUCCESS);
    bisection_computing(co, prec, a, b);
    return (SUCCESS);
}
