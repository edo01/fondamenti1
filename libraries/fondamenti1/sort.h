#pragma once

#include "element.h"

#define TEST 

#define INCREASING 1
#define DECREASING -1

#define TYPE_SORTING int

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


//test
#ifdef TEST
void stampResult();
#endif // TEST