#include <math.h>
#include "common.h"

/*
--------------------------------------------------------------------------
-------------------------------COMPLEX NUMBERS----------------------------
--------------------------------------------------------------------------
*/

void toPolar(double a, double b, double* modulo, double* argomento) {
    *modulo = sqrt(a * a + b * b);
    if (a != 0)
        *argomento = atan2(b, a);
    else
        *argomento = 3.14 / 2;
}

void sumComplex(double a, double b, double a2, double b2, double* a_final, double* b_final) {
    *a_final = a + a2;
    *b_final = b + b2;
}


/*--------------------------------------------------------------------------
-----------------------------------GENERAL----------------------------------
--------------------------------------------------------------------------*/

/*attenzione funziona fino a n inferiori a 13*/
int fact(int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    return n * fact(n - 1);
}

/*attenzione funziona fino a n ed m inferiori a 13*/
int binomioNewton(int n, int m)
{
    return fact(n) / (fact(m) * fact(n - m));
}

double doubleAbs(double a)
{
    return (a < 0 ? -a : a);
}


/*--------------------------------------------------------------------------
------------------------------GENERAL FUNCTIONS-----------------------------
--------------------------------------------------------------------------*/

#define UNDEFINED 1
#define NOT_INTEGRABLE 2
#define OK 0

int f(double x, double* result) {
    if (TRUE) {
        *result = x * x;
        return OK;
    }
    else return UNDEFINED;
}

double integral(double a, double b, int n)
{
    double intervallo = doubleAbs((b - a) / n), result = 0, increment = a;
    for (int i = 0; i < n; i++)
    {
        increment += i * intervallo;
        double y;
        if (f(increment, &y)) {
            //la funzione è definita
            double area_ret = intervallo * y;
            result += area_ret;
        }
    }
    return result;
}

double integrale_ricorsivo(double a, double b, int n) {
    double base = doubleAbs(b - a) / n;
    double y;
    if (f(a, &y)) {
        if (n == 1) {
            return base * y;
        }
        else {
            return (base * y) + integrale_ricorsivo(a + base, b, n - 1);
        }
    }
}