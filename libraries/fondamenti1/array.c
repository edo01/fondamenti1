#include "common.h";
#include <stdio.h>
#define TYPE int



// check the input
boolean check_input(TYPE input) {
	return TRUE;
}

boolean exit(TYPE input) {
	return input == 0;
}

int fill(TYPE a[], int dim) {
	TYPE input = 1, size = 0;
	while (!exit(input) && size < dim) 
	{
		scanf_s("%d", &input); //change this if input type is different from int
		while (!check_input(input)) 
			scanf_s("%d", &input);
		if (!exit(input)) {
			a[size] = input;
			size++;
		}
	}
	return size;
}

boolean compare_to(TYPE a, TYPE b) {
	return a == b;
}

boolean find(TYPE array[], int dim, TYPE el) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (compare_to(array[i], el)) found = TRUE;
	}
	return found;
}