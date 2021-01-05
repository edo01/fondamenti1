#pragma once
/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#ifndef ELEMENT_LIST
#define ELEMENT_LIST

#include <stdio.h>

#ifndef BOOLEAN_DEF
#define BOOLEAN_DEF

typedef int boolean;
#define TRUE 1
#define FALSE 0

#endif // !BOOLEAN_DEF

#ifndef TYPECOMPARE_DEF
#define TYPECOMPARE_DEF

typedef enum { higher, lower, equal } typeCompare;

#endif // !TYPECOMPARE_DEF
/*----------------EXAM space-------------------*/


typedef struct {
	int id;
} List_el;

/*----------------EXAM space-------------------*/


typedef List_el Element;

/*
	---------------------------------------------------------------------------------------------------------------------
	--------------------------------------------------  LIST ------------------------------------------------------------
	---------------------------------------------------------------------------------------------------------------------
*/

/// <summary>
/// Check if the first Element is equal to the second one.
/// </summary>
/// <param name="el">first Element</param>
/// <param name="el2">second Element</param>
/// <returns>TRUE if the Elements are equal, otherwise return FALSE</returns>
boolean isEqual(Element el, Element el2);

/// <summary>
/// Compare two Elements. Return a typeCompare value.
/// </summary>
/// <param name="el">first Element</param>
/// <param name="el2">second Element</param>
/// <returns>"higher" if the first is larger than the second one, "equal" if they are equal, "lower" if the second one is larger than the first one. </returns>
typeCompare compareTo_el(Element el, Element el2);

/// <summary>
/// copy an Element inside of another Element.
/// </summary>
/// <param name="el"> The Element to copy.</param>
/// <param name="dest"> The destination.</param>
void put(Element el, Element* dest);

/// <summary>
/// Print an Element.
/// </summary>
/// <param name="el1"> The Element to print.</param>
void print_el(Element el1);

#endif