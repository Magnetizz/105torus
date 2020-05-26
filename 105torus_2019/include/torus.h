/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** my.h
*/

#ifndef __TORUS_H__
#define __TORUS_H__

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct coef_t {
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
} coef_t;

typedef struct deriv_t {
    double d0;
    double d1;
    double d2;
    double d3;
} deriv_t;

void help_display(void);
int error_handling(int ac, char **av);

double compute_equation(coef_t *co, double x);
double compute_derivee(deriv_t *d, double x);
int does_it_stop(double sol, int prec);

int bisection_method(coef_t *c, int prec, double a, double b);
int newton_method(coef_t *c, deriv_t *d, int prec, double x0);
int secant_method(coef_t *c, int prec, double x0, double x1);

#define FAIL 84
#define SUCCESS 0
#define ERROR_NBRARG "this program must take 7 arguments (see with -h)\n"
#define ERROR_OPT "method is invalid (see with -h)\n"
#define ERROR_COEF "the coefficients must be numbers (see with -h)\n"
#define ERROR_N "the precision must be a positive number (see with -h)\n"
#define ERROR_DIV "division by 0\n"

#endif
