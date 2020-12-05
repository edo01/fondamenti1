#pragma once

#include "element.h"

#define ELEMENT element

typedef struct list_element{ 
	ELEMENT value;
    struct list_element* next; 
} item;

typedef item* list;

//primitive

/// <summary>
/// Returns an empty list.
/// </summary>
/// <returns>An empty list.</returns>
list emptyList();

/// <summary>
/// Check if a list is empty.
/// </summary>
/// <param name="l">The list</param>
/// <returns>TRUE if the list is empty, otherwise returns FALSE</returns>
boolean empty(list l);

/// <summary>
/// Returns the value of the head of the list. If the list is empty call exit(-1). The head of [7,2,3,4] is 7.
/// </summary>
/// <param name="l"></param>
/// <returns>The value of the list</returns>
ELEMENT head(list l);

/// <summary>
/// Returns the pointer to the second element of the list. If the list is empty call exit(-1). The tail of [7,2,3,4] is [2,3,4].
/// </summary>
/// <param name="l"></param>
/// <returns>The tail of the list</returns>
list tail(list l);

/// <summary>
/// The constructor of the list. Create a new list from a previuos list and a new element. cons(7,[2,3,4])->[7,2,3,4].
/// </summary>
/// <param name="e">the new element to add</param>
/// <param name="l">the list where to add the element</param>
/// <returns>The new list where the head is the new element and the tail is the previous list.</returns>
list cons(ELEMENT e, list l);

/// <summary>
/// Return the last element of the list. If the list is empty return NULL.
/// </summary>
/// <param name="l"></param>
/// <returns></returns>
item* lastElement(list l);

/// <summary>
/// Calculate the lenght of the list.
/// </summary>
/// <param name="l"></param>
/// <returns>Returns the lenght of the list.</returns>
int lenght(list l);

//===========================================================//
//-----------------------------------------------------------//
//-----------------------------------------------------------//
//===========================================================//

/// <summary>
/// Copy and reverse the given list.
/// </summary>
/// <param name="l">The list to reverse</param>
/// <returns>A copy of the list reversed.</returns>
list reverse(list l);

list append(list l, list l2);

/// <summary>
/// A copy of the two list where the second one is appended to the first one.
/// </summary>
/// <param name="l"></param>
/// <param name="l2"></param>
/// <returns>The first list plus the second one.</returns>
list append_c(list l, list l2);

/// <summary>
/// Check if a given element is a member of the list.
/// </summary>
/// <param name="el">The element to search</param>
/// <param name="l">the list</param>
/// <returns>TRUE if the element is present inside the list, otherwise returns FALSE.</returns>
boolean isMember(ELEMENT el, list l);

/// <summary>
/// Print all the element of the list
/// </summary>
void show_list(list l);

/// <summary>
/// Returns a copy of the list.
/// </summary>
/// <param name="l"></param>
/// <returns>Returns a copy of the list.</returns>
list copy(list l);

/// <summary>
/// Delete a given element from the list.
/// </summary>
/// <param name="el"> The element to delete</param>
/// <returns>A copy of the list without the element given in input.</returns>
list delete(ELEMENT el, list l);

/// <summary>
/// Insert an element with the order given(INCREASING/DECREASING).
/// </summary>
/// <param name="el">The element to add to the list</param>
/// <param name="l">The ordered list</param>
/// <param name="ord">INCREASING/DECREASING</param>
/// <returns>Returns an ordered list.</returns>
list insord(ELEMENT el, list l, int ord);
