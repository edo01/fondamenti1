/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*TODO
* test
* check input
*/


TYPE* subArray(TYPE* a, int dimA, TYPE first, TYPE last, int* dimS) {
	TYPE* p = a;
	int dim_volatile = 0;
	boolean finish = FALSE;
	for (int i = 0; i < dimA && !finish; i++) {
		if (isEqualArray(a[i], first)) {
			p += i;
			dim_volatile = i;
		}
		else if (isEqualArray(a[i], last)) {
			*dimS = i - dim_volatile + 1;
			finish = TRUE;
		}
	}
	return p;
}

TYPE* deleteDuplicates(TYPE a[], int dim, int* newDim) {
	int count = 1;
	TYPE* no_duplicate;
	for (int i = 0; i < dim - 1; i++) {
		if (!find(&a[i + 1], dim - i, a[i])) count++;
	}
	no_duplicate = (TYPE*)malloc(sizeof(TYPE) * count);
	if (no_duplicate == NULL) exit(BAD_MALLOC_C);

	*newDim = count;
	count = 0;
	for (int i = 0; i < dim - 1; i++) {
		if (!find(&a[i + 1], dim - i, a[i])) {
			no_duplicate[count] = a[i];
			count++;
		}
	}
	no_duplicate[count] = a[dim - 1];
	return no_duplicate;
}


void fill_random(int a[], int dim) {
	for (int i = 0; i < dim; i++) {
		a[i] = 1 + rand() % 100;
	}
}

boolean find(TYPE array[], int dim, TYPE el) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (isEqualArray(array[i], el)) found = TRUE;
	}
	return found;
}

//manca find_position
boolean find_position(TYPE array[], int dim, TYPE el, int* pos) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (isEqualArray(array[i], el)) found = TRUE, * pos = i;
	}
	return found;
}

void printArray(TYPE a[], int dim) {
	for (int i = 0; i < dim; i++) print_elArray(a[i]), printf("\n");
}