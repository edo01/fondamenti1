/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include "mystring.h"

/*
* TODO: add some functions
* remember you atoi, atof ecc..
*/


void replace(char s[], char toReplaceChars[], int dim, char replaceChar) {
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		if (findChar(s[i], toReplaceChars, dim)) {
			s[i] = replaceChar;
		}
	}
}


boolean findChar(char c, char a[], int dim) {
	boolean result = FALSE;
	int count = 0;
	while (!result && count < dim) {
		if (c == a[count]) result = TRUE;
		count++;
	}
	return result;
}