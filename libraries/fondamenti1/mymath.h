#pragma once 
/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/
#ifndef MYMATH
#define MYMATH

#include <math.h>

#include "elementArray.h"

/****************complex*****************/
void toPolar(double, double, double*, double*);
void sumComplex(double, double, double, double, double*, double*);
/*----------- --------------------------*/

/****************general maths*****************/
int fact(int);
int binomioNewton(int, int);
double doubleAbs(double);
/*-------------------------------------------------*/

#endif // !MYMATH

