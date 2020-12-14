
#ifndef ARRAY
#define ARRAY

#include "element.h"

#define TYPE_SUBARRAY element
#define TYPE_FILL element
#define TYPE_FIND element

//TODO: TEST LIBRARIES.


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
* Find inside of an array the given element el
*
* return 1 if it is present, otherwise return 0
*/
boolean find(TYPE_FIND array[], int dim, TYPE_FIND el);

boolean find_position(TYPE_FIND array[], int dim, TYPE_FIND el, int* pos);

void fill_random(int a[], int dim);

#endif // !ARRAY