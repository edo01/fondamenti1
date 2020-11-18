#include "common.h"
#include <stdio.h>

#define TYPE int

boolean compare_to(TYPE a, TYPE b) {
	return a == b;
}

TYPE* subArray(TYPE* a, int dimA, TYPE first, TYPE last, int* dimS) {
	TYPE* p = a;
	int dim_volatile = 0;
	boolean finish = FALSE;
	for (int i = 0; i < dimA && !finish; i++) {
		if (compare_to(a[i], first)) {
			p += i;
			dim_volatile = i;
		}
		else if (compare_to(a[i], last)) {
			*dimS = i - dim_volatile + 1;
			finish = TRUE;
		}
	}
	return p;
}

// check the input
boolean _check_input(TYPE input) {
	return TRUE;
}

boolean _isExitValue(TYPE input) {
	return input == 0;
}

int fill(TYPE a[], int dim) {
	TYPE input = 1, size = 0;
	while (!_isExitValue(input) && size < dim)
	{
		scanf_s("%d", &input); //change this if input type is different from int
		while (!_check_input(input))
			scanf_s("%d", &input);
		if (!_isExitValue(input)) {
			a[size] = input;
			size++;
		}
	}
	return size;
}

boolean find(TYPE array[], int dim, TYPE el) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (compare_to(array[i], el)) found = TRUE;
	}
	return found;
}