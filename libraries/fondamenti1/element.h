
#ifndef ELEMENT
#define ELEMENT

#include <stdio.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef enum { more, less, equal } typeCompare;

/*----------------EXAM space-------------------*/

/*----------------exam space-------------------*/


typedef int Element;

/// <summary>
/// Check if the first Element is equal to the second.
/// </summary>
/// <param name="el">first Element</param>
/// <param name="el2">second Element</param>
/// <returns>TRUE if the Elements are equal, otherwise returns FALSE</returns>
boolean isEqual(Element el, int el2);

/// <summary>
/// Compare to Elements. Returns a typeCompare value.
/// </summary>
/// <param name="el">first Element</param>
/// <param name="el2">second Element</param>
/// <returns>"more" if the first is larger than the second, "equal" if they are equal, less if the second is larger than the first </returns>
typeCompare compareTo_el(Element el, Element el2);

/// <summary>
/// copy an Element inside of another Element.
/// </summary>
/// <param name="el"> the Element to copy</param>
/// <param name="dest"> the destination</param>
void put(Element el, Element* dest);

/// <summary>
/// Ask from input an Element.
/// </summary>
/// <returns>the Element taken from the input.</returns>
Element input_el();

/// <summary>
/// Print an Element.
/// </summary>
/// <param name="el1">the Element to print</param>
void print_el(Element el1);

#endif