
#ifndef ELEMENT
#define ELEMENT

#include <stdio.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef enum { more, less, equal } typeCompare;

/*----------------EXAM space-------------------*/

/*----------------exam space-------------------*/


typedef int element;

/// <summary>
/// Check if the first element is equal to the second.
/// </summary>
/// <param name="el">first element</param>
/// <param name="el2">second element</param>
/// <returns>TRUE if the elements are equal, otherwise returns FALSE</returns>
boolean isEqual(element el, int el2);

/// <summary>
/// Compare to elements. Returns a typeCompare value.
/// </summary>
/// <param name="el">first element</param>
/// <param name="el2">second element</param>
/// <returns>"more" if the first is larger than the second, "equal" if they are equal, less if the second is larger than the first </returns>
typeCompare compareTo_el(element el, element el2);

/// <summary>
/// copy an element inside of another element.
/// </summary>
/// <param name="el"> the element to copy</param>
/// <param name="dest"> the destination</param>
void put(element el, element* dest);

/// <summary>
/// Ask from input an element.
/// </summary>
/// <returns>the element taken from the input.</returns>
element input_el();

/// <summary>
/// Print an element.
/// </summary>
/// <param name="el1">the element to print</param>
void print_el(element el1);

#endif