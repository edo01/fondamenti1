#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*TODO
* test
* check input
*/

boolean equal_subArray(TYPE_SUBARRAY* a, TYPE_SUBARRAY* b) {
	return isEqual(*a, *b);
}

TYPE_SUBARRAY* subArray(TYPE_SUBARRAY* a, int dimA, TYPE_SUBARRAY first, TYPE_SUBARRAY last, int* dimS) {
	TYPE_SUBARRAY* p = a;
	int dim_volatile = 0;
	boolean finish = FALSE;
	for (int i = 0; i < dimA && !finish; i++) {
		if (equal_subArray(&a[i], &first)) {
			p += i;
			dim_volatile = i;
		}
		else if (equal_subArray(&a[i], &last)) {
			*dimS = i - dim_volatile + 1;
			finish = TRUE;
		}
	}
	return p;
}

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

void fill_random(int a[], int dim) {
	for (int i = 0; i < dim; i++) {
		a[i] = 1 + rand()%100;
	}
}

boolean equal_find(TYPE_FIND *a, TYPE_FIND *b) {
	return isEqual(*a, *b);
}

boolean find(TYPE_FIND array[], int dim, TYPE_FIND el) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (equal_find(&array[i], &el)) found = TRUE;
	}
	return found;
}

//manca find_position
boolean find_position(TYPE_FIND array[], int dim, TYPE_FIND el, int *pos) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (equal_find(&array[i], &el)) found = TRUE, *pos = i;
	}
	return found;
}