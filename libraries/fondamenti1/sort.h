
#ifndef SORT
#define SORT

#include "element.h"

#define INCREASING 1
#define DECREASING -1

#define TYPE_SORTING element

/// <summary>
/// Sort an array of given dimension
/// </summary>
/// <param name="a">the array</param>
/// <param name="dim">dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void naiveSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of given dimension
/// </summary>
/// <param name="a">the array</param>
/// <param name="dim">dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void bubbleSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of given dimension
/// </summary>
/// <param name="a">the array</param>
/// <param name="dim">dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void insertSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of given dimension
/// </summary>
/// <param name="a">the array</param>
/// <param name="dim">dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void mergeSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of given dimension
/// </summary>
/// <param name="a">the array</param>
/// <param name="dim">dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void quickSort(TYPE_SORTING a[], int dim, int order);


int compareToSorting(TYPE_SORTING* el, TYPE_SORTING* el2, int ord);

//test
#ifdef TEST
void stampResult();
#endif // TEST

#endif