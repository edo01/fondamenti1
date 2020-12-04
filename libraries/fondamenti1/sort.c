#include "sort.h"
#include "array.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST
/*
--------------------------------------------------------------------------
---------------------------SORTING ALGORITHMS-----------------------------
--------------------------------------------------------------------------
*/


/*TODO:
* check the input
*/
#ifdef TEST

int swapCount = 0, compCount = 0;
void incSwap() { swapCount++; }
void incComp() { compCount++; }

void stampResult() {
	printf("numero di comparazioni:%d\n", compCount);
	printf("numero di swap:%d\n\n", swapCount);
}
#endif // TEST


void swap(TYPE_SORTING* el1, TYPE_SORTING* el2) {

#ifdef TEST
	incSwap();
#endif // TEST

	TYPE_SORTING temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}

int compareToSorting(TYPE_SORTING *el1, TYPE_SORTING *el2, int order) {
#ifdef	TEST
	incComp();
#endif // TEST
	int result;

	//CHANGE THIS AREA
	if (*el1 > *el2)
		result = 1;
	else if (*el1 < *el2)
		result = -1;
	else result = 0;
	//CHANGE THIS AREA

	// invert the result if the    is DECREASING(-1)
	result = result * order;
	return result; 
}

void findMaxPosition(TYPE_SORTING a[], int dim, int order) {
	int max_min_index = 0; // save the position of the element
	for (int i = 1; i < dim; i++) {
		if (compareToSorting(&a[i], &a[max_min_index], order)>0) {
			max_min_index = i;
		}
	}
	swap(&a[max_min_index], &a[dim - 1]);
}

void naiveSort(TYPE_SORTING a[], int dim, int order) {
	for (int i = dim; i > 0; i--) {
		findMaxPosition(a, i, order);
	}
}

void bubbleSort(TYPE_SORTING a[], int dim, int order) {
	boolean flag = FALSE;
	for (int i = 0; i < (dim - 1) && !flag; i++) {
		flag = TRUE; // if remain TRUE the array is sorted
		for (int j = 0; (j < dim - 1 - i); j++) {
			if (compareToSorting(&a[j], &a[j + 1], order)>0) {
				swap(&a[j], &a[j + 1]);
				flag = FALSE;
			}
		}
	}
}

void translate(TYPE_SORTING a[], int dim, int pos) {
	// remember to check if pos<dim
	for (int i = dim - 1; i >= pos; i--) {
		a[i + 1] = a[i];
		incSwap();
	}
}

void insert(TYPE_SORTING a[], int dim, TYPE_SORTING el, int order) {
	boolean inserted = FALSE;
	for (int i = 0; i < dim && !inserted; i++) {
		if (compareToSorting(&a[i], &el, order)>0) {
			translate(a, dim, i);
			a[i] = el;
			inserted = TRUE;
		}
	}
}

void insertSort(TYPE_SORTING a[], int dim, int order) {
	for (int i = 1; i < dim - 1; i++) {
		insert(a, i + 1, a[i + 1], order);
	}
}

//attention, a[] is the result
void merge(TYPE_SORTING a[], int dimA, TYPE_SORTING b[], int dimB, int order) {
	int dimResult = (dimA + dimB);
	TYPE_SORTING* temp = (TYPE_SORTING*)malloc(dimResult * sizeof(TYPE_SORTING));
	if (temp == NULL) return;
	int j_done = 0, result_index = 0;
	for (int i = 0; i < dimA; i++) {
		for (int j = j_done; j < dimB; j++) {
			if (compareToSorting(&a[i], &b[j], order)>0) {
				temp[result_index++] = b[j_done++];
			}
		}
		temp[result_index++] = a[i];
	}
	for (int i = j_done; i < dimB; i++) {
		temp[result_index] = b[i];
		result_index++;
	}

	// copy the result inside of a[]
	for (int i = 0; i < dimResult; i++) {
		a[i] = temp[i];
	}
	free(temp);
}

void mergeSort(TYPE_SORTING a[], int dim, int order) {
	if (dim <= 1) return;
	int split_index = dim / 2;
	mergeSort(a, split_index, order);
	mergeSort(&a[split_index], dim - split_index, order);
	merge(a, split_index, &a[split_index], dim - split_index, order);
}

void quickSort(TYPE_SORTING a[], int dim, int order) {
	boolean flag = FALSE;
	if (dim <= 1) {
		flag = TRUE;
	}
	else if (dim == 2) {
		if (!compareToSorting(&a[1], &a[0], order)>0) {
			swap(&a[0], &a[1]);
		}
		flag = TRUE;
	}
	TYPE_SORTING pivot = a[dim - 1];
	int j = dim - 2, i = 0;
	int pivot_position = 0;
	if (!flag) {
		while (pivot_position != j) {
			if (!compareToSorting(&pivot, &a[i], order)>0) {
				while (!flag && i != j) {
					if (!compareToSorting(&a[j], &pivot, order)>0) {
						swap(&a[i], &a[j]);
						flag = TRUE;
					}
					j--;
				}
				flag = FALSE;
			}
			pivot_position = i;
			i++;
		}
		if (!compareToSorting(&pivot, &a[pivot_position], order)>0) {
			swap(&a[pivot_position], &a[dim - 1]);
		}
		else {
			pivot_position = dim - 1;
		}

		quickSort(a, pivot_position, order);
		if (pivot_position != (dim - 2)) quickSort(&a[pivot_position + 1], dim - pivot_position - 1, order);
	}
}
