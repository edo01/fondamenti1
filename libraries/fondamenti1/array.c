#include "common.h"
#include <stdio.h>


#define TYPE_COMPARE_TO int

boolean compareTo(TYPE_COMPARE_TO a, TYPE_COMPARE_TO b) {
	return a == b;
}

#define TYPE_SUBARRY int

boolean compareTo_subArray(TYPE_SUBARRY a, TYPE_SUBARRY b) {
	return a == b;
}

TYPE_SUBARRY* subArray(TYPE_SUBARRY* a, int dimA, TYPE_SUBARRY first, TYPE_SUBARRY last, int* dimS) {
	TYPE_SUBARRY* p = a;
	int dim_volatile = 0;
	boolean finish = FALSE;
	for (int i = 0; i < dimA && !finish; i++) {
		if (compareTo_subArray(a[i], first)) {
			p += i;
			dim_volatile = i;
		}
		else if (compareTo_subArray(a[i], last)) {
			*dimS = i - dim_volatile + 1;
			finish = TRUE;
		}
	}
	return p;
}

#define TYPE_FILL int
// check the input
boolean _check_input(TYPE_FILL input) {
	return TRUE;
}

boolean _isExitValue(TYPE_FILL input) {
	return input == 0;
}

int fill(TYPE_FILL a[], int dim) {
	TYPE_FILL input = 1, size = 0;
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

#define TYPE_FIND int

boolean compareTo_find(TYPE_FIND a, TYPE_FIND b) {
	return a == b;
}

boolean find(TYPE_FIND array[], int dim, TYPE_FIND el) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (compareTo_find(array[i], el)) found = TRUE;
	}
	return found;
}