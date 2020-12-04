/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Powered by Edoardo Carrà
*/
#pragma warning(disable:4996)

#include <string.h>
#include <stdio.h>
#include "element.h"
#include <stdlib.h>
#include "array.h"
#include "sort.h"
#include "esercizi.h"
#include "list.h"


#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE 

/*
void stamp(int p[], int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%d\t", p[i]);
	}
	printf("\n");
}

void isSorted(int p[], int dim) {
	for (int i = 0; i < dim-1; i++) {
		if (p[i] > 	p[i + 1]) {
			printf("\nNON ORDINATO");
			return;
		}
	}
}


int main() {
	for (int dim = 0; dim < 20; dim++) {
		printf("\n\nDIMENSIONE %d\n", dim);
		int* p = malloc(dim * sizeof(int));

		printf("NAIVE\n");
		fill_random(p, dim);
		stamp(p, dim);
		naiveSort(p, dim, INCREASING);
		stamp(p, dim);
		isSorted(p, dim);

		printf("\n\n");
		printf("BUBBLE\n");
		fill_random(p, dim);
		stamp(p, dim);
		bubbleSort(p, dim, INCREASING);
		stamp(p, dim);
		isSorted(p, dim);

		printf("\n\n");
		printf("INSERT\n");
		fill_random(p, dim);
		stamp(p, dim);
		insertSort(p, dim, INCREASING);
		stamp(p, dim);
		isSorted(p, dim);

		printf("\n\n");
		printf("MERGE\n");
		fill_random(p, dim);
		stamp(p, dim);
		mergeSort(p, dim, INCREASING);
		stamp(p, dim);
		isSorted(p, dim);
		free(p);
	}
	return 0;
}
*/

int main() {
	int input;
	list l = emptyList();

	for (int i = 0; i < 10; i++) {
		printf("\ninserisci un numero:");
		scanf("%d", &input);
		if (input == 0) break;
		l = cons(input, l);
	}
	show_list(copy(l));
	list l2 = emptyList();

	for (int i = 0; i < 10; i++) {
		printf("\ninserisci un numero:");
		scanf("%d", &input);
		if (input == 0) break;
		l2 = cons(input, l2);
	}
	show_list(l2);

	show_list(append_c(l, l2));
	return 0;
}