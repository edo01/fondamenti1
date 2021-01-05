#pragma once
/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#ifndef SORT
#define SORT

#include "elementArray.h"
#include "error.h"

#define INCREASING 1
#define DECREASING -1

#define TYPE_SORTING ElementArray

/// <summary>
/// Sort an array of a given dimension
/// </summary>
/// <param name="a">The array</param>
/// <param name="dim">Dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void naiveSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of a given dimension
/// </summary>
/// <param name="a">The array</param>
/// <param name="dim">Dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void bubbleSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of a given dimension
/// </summary>
/// <param name="a">The array</param>
/// <param name="dim">Dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void insertSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of a given dimension
/// </summary>
/// <param name="a">The array</param>
/// <param name="dim">Dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void mergeSort(TYPE_SORTING a[], int dim, int order);

/// <summary>
/// Sort an array of a given dimension
/// </summary>
/// <param name="a">The array</param>
/// <param name="dim">Dimension of the array</param>
/// <param name="order">INCREASING/DECREASING</param>
void quickSort(TYPE_SORTING a[], int dim, int order);

int compareToSorting(TYPE_SORTING* el1, TYPE_SORTING* el2, int order);

/// <summary>
/// Verify that the array is sorted
/// </summary>
/// <param name="a">The array</param>
/// <param name="dim">The dimension of the array</param>
/// <param name="ord">INCREASING/DECREASING</param>
/// <returns>If the array is sorted</returns>
boolean isSorted(TYPE_SORTING a[], int dim, int ord);

#endif