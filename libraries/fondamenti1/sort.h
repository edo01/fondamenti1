#pragma once

#include "element.h"

#define INCREASING 1
#define DECREASING -1

#define TYPE_SORTING int

void naiveSort(TYPE_SORTING a[], int dim, int order);

void bubbleSort(TYPE_SORTING a[], int dim, int order);

void insertSort(TYPE_SORTING a[], int dim, int order);

void mergeSort(TYPE_SORTING a[], int dim, int order);

void quickSort(TYPE_SORTING a[], int dim, int order);


//test
void stampResult();