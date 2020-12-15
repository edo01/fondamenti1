#include "sort.h"
#include "array.h"

#include <stdio.h>
#include <stdlib.h>
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

//DEPENDS ON THE TYPE OF THE ELEMENT
void swap(TYPE_SORTING* el1, TYPE_SORTING* el2) {

#ifdef TEST
	incSwap();
#endif // TEST

	TYPE_SORTING temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}

//DEPENDS ON THE TYPE OF THE ELEMENT
int compareToSorting(TYPE_SORTING *el1, TYPE_SORTING *el2, int order) {
#ifdef	TEST
	incComp();
#endif // TEST
	int result;

	if (compareTo_el(*el1, *el2)==more)
		result = -1;
	else if (compareTo_el(*el1, *el2)==less)
		result = 1;
	else result = 0;

	// The result is >0 if the order is correct and <0 if the order is incorrect
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
	int i = pos - 1, x = a[pos]; 
	while (i >= 0 && compareToSorting(&x, &a[i], order)>0) {
		a[i + 1] = a[i]; /* traslate */
		i--; 
	}
	a[i + 1] = x; /* insert the element */
}

void insertSort(TYPE_SORTING a[], int dim, int order) {
	for (int i = 1; i < dim; i++) {
		insert(a, i, order);
	}
}

//attention, a[] is the result
void merge(TYPE_SORTING a[], int dimA, TYPE_SORTING b[], int dimB, int order) {
	int dimResult = (dimA + dimB);
	TYPE_SORTING* temp = (TYPE_SORTING*) malloc(dimResult * sizeof(TYPE_SORTING));
	if (temp == NULL) exit(-1);//check malloc
	int j_done = 0, result_index = 0;
	for (int i = 0; i < dimA; i++) {
		for (int j = j_done; j < dimB; j++) {
			if (compareToSorting(&a[i], &b[j], order)<0) {
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


void quickSortR(TYPE_SORTING a[], int iniz, int fine, int order) {
	int i, j, iPivot;
	TYPE_SORTING pivot; 
	if (iniz < fine) {
		i = iniz; 
		j = fine;
		iPivot = fine;
		put(a[iPivot], &pivot);
		do  /* trova la posizione del pivot */ 
		{ 
			while (i < j && (compareToSorting(&a[i], &pivot, order)>=0)) i++; 
			while (j > i && (compareToSorting(&a[j], &pivot, order)<=0)) j--;
			if (i < j) swap(&a[i], &a[j]); 
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && !isEqual(a[i],a[iPivot])) 
		{ 
			swap(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)  
			quickSortR(a, iniz, iPivot - 1, order); 
		if (iPivot + 1 < fine)  
			quickSortR(a, iPivot + 1, fine, order);
	} /* (iniz < fine) */
} /* quickSortR */


void quickSort(TYPE_SORTING a[], int dim, int order) {
	if (dim < 3 ) return;
	quickSortR(a, 0, dim - 1, order);
}

