/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** display the usage
*/

#include "torus.h"

void help_display(void)
{
    printf("USAGE\n");
    printf("    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n");
    printf("    opt\t\tmethod option:\n");
    printf("\t\t\t1 for the bisection method\n");
    printf("\t\t\t2 for Newton's method\n");
    printf("\t\t\t3 for the secant method\n");
    printf("    a[0-4]\tcoefficients of the equation\n");
    printf("    n\t\tprecision (the application of the polynomial");
    printf("to the solution should be smaller than 10^-n)\n");
}
