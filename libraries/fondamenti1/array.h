#pragma once

/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#ifndef ARRAY
#define ARRAY

#include "elementArray.h"
#include "error.h"

#define TYPE ElementArray

//TODO: TEST LIBRARIES.

/*
* Extract from an array a sub array
*
* TYPE a[] the array to extract from
* int dimA the dimension of the a-array
* TYPE first the first element to search
* TYPE last the last element to search
* int* dimS is the dimension of the array extracted
*
* return the first element of the subarray
*/
TYPE* subArray(TYPE* a, int dimA, TYPE first, TYPE last, int* dimS);

/*
* Find inside of an array the given element el
*
* return 1 if it is present, otherwise return 0
*/
boolean find(TYPE array[], int dim, TYPE el);

TYPE* deleteDuplicates(TYPE a[], int dim, int* newDim);

boolean find_position(TYPE array[], int dim, TYPE el, int* pos);

void fill_random(int a[], int dim);

void printArray(TYPE a[], int dim);

#endif // !ARRAY