/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include "sort.h"
#include "array.h"

#include <stdio.h>
#include <stdlib.h>
/*
--------------------------------------------------------------------------
---------------------------SORTING ALGORITHMS-----------------------------
--------------------------------------------------------------------------
*/


void swap(TYPE_SORTING* el1, TYPE_SORTING* el2) {

	TYPE_SORTING temp;
	putArray(*el1, &temp);
	putArray(*el2, el1);
	putArray(temp, el2);
}

int compareToSorting(TYPE_SORTING *el1, TYPE_SORTING *el2, int order) {
	int result;

	if (compareTo_elArray(*el1, *el2)==higher)
		result = -1;
	else if (compareTo_elArray(*el1, *el2)==lower)
		result = 1;
	else result = 0;

	// The result is >0 if the order is right and <0 if the order is wrong
	// return 0 if the two elements are equal
	result = result * order;
	return result; 
}

void findMaxPosition(TYPE_SORTING a[], int dim, int order) {
	int max_min_index = 0; // save the position of the max/min element
	for (int i = 0; i < dim; i++) {
		if (compareToSorting(&a[i], &a[max_min_index], order)<0) {
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
			if (compareToSorting(&a[j], &a[j + 1], order)<0) {
				swap(&a[j], &a[j + 1]);
				flag = FALSE;
			}
		}
	}
}

void insert(TYPE_SORTING a[], int pos, int order) {
	int i = pos - 1;
	TYPE_SORTING x;
	putArray(a[pos], &x);
	while (i >= 0 && compareToSorting(&x, &a[i], order)>0) {
		putArray(a[i], &a[i + 1]); // traslate
		i--; 
	}
	putArray(x, &a[i + 1]); // insert the element 
}

void insertSort(TYPE_SORTING a[], int dim, int order) {
	for (int i = 1; i < dim; i++) {
		insert(a, i, order);
	}
}

void merge(TYPE_SORTING a[], int dimA, TYPE_SORTING b[], int dimB, int order) {
	int dimResult = (dimA + dimB);
	TYPE_SORTING* temp = (TYPE_SORTING*) malloc(dimResult * sizeof(TYPE_SORTING));
	if (temp == NULL) exit(BAD_MALLOC_C);
	int j_done = 0, result_index = 0;
	for (int i = 0; i < dimA; i++) {
		for (int j = j_done; j < dimB; j++) {
			if (compareToSorting(&a[i], &b[j], order)<0) {
				putArray(b[j_done++], &temp[result_index++]);
			}
		}
		putArray(a[i], &temp[result_index++]);
	}
	for (int i = j_done; i < dimB; i++) {
		putArray(b[i], &temp[result_index]);
		result_index++;
	}

	// copy the result inside of a[]
	for (int i = 0; i < dimResult; i++) {
		putArray(temp[i], &a[i]);
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


void quickSortR(TYPE_SORTING a[], int iniz, int fine, int order) {
	int i, j, iPivot;
	TYPE_SORTING pivot; 
	if (iniz < fine) {
		i = iniz; 
		j = fine;
		iPivot = fine;
		putArray(a[iPivot], &pivot);
		do 
		{ 
			while (i < j && (compareToSorting(&a[i], &pivot, order)>=0)) i++; 
			while (j > i && (compareToSorting(&a[j], &pivot, order)<=0)) j--;
			if (i < j) swap(&a[i], &a[j]); 
		}
		while (i < j);

		if (i != iPivot && compareToSorting(&a[i], &a[iPivot], order)!=0)
		{ 
			swap(&a[i], &a[iPivot]);
			iPivot = i;
		}

		if (iniz < iPivot - 1)  
			quickSortR(a, iniz, iPivot - 1, order); 
		if (iPivot + 1 < fine)  
			quickSortR(a, iPivot + 1, fine, order);
	}
} 

void quickSort(TYPE_SORTING a[], int dim, int order) {
	if (dim < 3 ) return;
	quickSortR(a, 0, dim - 1, order);
}

boolean isSorted(TYPE_SORTING a[], int dim, int ord) {
	for (int i = 0; i < dim-1; i++) {
		if (compareToSorting(&a[i], &a[i + 1], ord) < 0) return FALSE;
	}
	return TRUE;
}
