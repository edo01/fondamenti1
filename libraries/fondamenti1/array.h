#pragma once

#include "element.h"

#define TYPE_COMPARE_TO int
#define TYPE_SUBARRAY int
#define TYPE_FILL int
#define TYPE_FIND int


/* 
* Fill the array from stdin
* TYPE a[] is the array to fill
* int dim is the  physical dimension of the array
* 
* return the logical dimension of the array 
*/
int fill(TYPE_FILL a[], int dim);

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
TYPE_SUBARRAY* subArray(TYPE_SUBARRAY* a, int dimA, TYPE_SUBARRAY first, TYPE_SUBARRAY last, int* dimS);

/*
* Compare two elements of the same type
* 
* return 1 if they are the equal, otherwise return 0
*/
boolean compareTo(TYPE_COMPARE_TO a, TYPE_COMPARE_TO b);

/*
* Find inside of an array the given element el
* 
* return 1 if it is present, otherwise return 0
*/
boolean find(TYPE_FIND array[], int dim, TYPE_FIND el);

boolean find_position(TYPE_FIND array[], int dim, TYPE_FIND el, int* pos);

void fill_random(int a[], int dim);