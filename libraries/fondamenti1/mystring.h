#pragma once

/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carr� Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
#include "elementArray.h"

void replace(char s[], char toReplaceChars[], int dim, char replaceChar);

boolean findChar(char c, char a[], int dim);

#endif // !MYSTRING_H
