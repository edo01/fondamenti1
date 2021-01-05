#pragma once
/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/
#ifndef LIST
#define LIST


#define INCREASING 1
#define DECREASING -1

#include "elementList.h"
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#define TYPE_LIST Element

typedef struct list_element {
	TYPE_LIST value;
	struct list_element* next;
} item;

typedef item* list;

//primitive

/// <summary>
/// Return an empty list.
/// </summary>
/// <returns>An empty list.</returns>
list emptyList();

/// <summary>
/// Check if a list is empty.
/// </summary>
/// <param name="l">The list.</param>
/// <returns>TRUE if the list is empty, otherwise return FALSE.</returns>
boolean empty(list l);

/// <summary>
/// Return the value of the head of the list. If the list is empty call exit(BAD_OPERATION_ON_EMPTY_LIST). The head of the list [7,2,3,4] is 7.
/// </summary>
/// <param name="l">The list.</param>
/// <returns>The value of the head of the list.</returns>
TYPE_LIST head(list l);

/// <summary>
/// Return the pointer to the second element of the list. If the list is empty call exit(BAD_OPERATION_ON_EMPTY_LIST). The tail of [7,2,3,4] is [2,3,4].
/// </summary>
/// <param name="l">The list.</param>
/// <returns>The tail of the list.</returns>
list tail(list l);

/// <summary>
/// The constructor of the list: create a new list from a previuos list and from a new element. cons(7,[2,3,4])->[7,2,3,4].
/// </summary>
/// <param name="e">The new element to add.</param>
/// <param name="l">The list where the element has to be added.</param>
/// <returns>The new list where the head is the new element and the tail is the list passed as a parameter.</returns>
list cons(TYPE_LIST e, list l);

/// <summary>
/// Return the last element of the list. If the list is empty return NULL.
/// </summary>
/// <param name="l">The list.</param>
/// <returns></returns>
item* lastElement(list l);

/// <summary>
/// Calculate the length of the list.
/// </summary>
/// <param name="l"></param>
/// <returns>Returns the length of the list.</returns>
int length(list l);

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

/// <summary>
/// A copy of the two lists where the second one is hung to the first one.
/// </summary>
/// <param name="l"></param>
/// <param name="l2"></param>
/// <returns>The first list plus the second one.</returns>
list append(list l, list l2);

/// <summary>
/// Check if a given element is a member of the list.
/// </summary>
/// <param name="el">The element to search</param>
/// <param name="l">the list</param>
/// <returns>TRUE if the element is present inside the list, otherwise returns FALSE.</returns>
boolean isMember(TYPE_LIST el, list l);

/// <summary>
/// Print all the elements of the list.
/// </summary>
void show_list(list l);

/// <summary>
/// Return a copy of the list.
/// </summary>
/// <param name="l"></param>
/// <returns>Return a copy of the list.</returns>
list copy(list l);

/// <summary>
/// Delete a given element from the list.
/// </summary>
/// <param name="el"> The element to delete</param>
/// <returns>A copy of the list without the element given in input.</returns>
list delete(TYPE_LIST el, list l);

/// <summary>
/// Insert an element following the order given(INCREASING/DECREASING).
/// </summary>
/// <param name="el">The element to add to the list.</param>
/// <param name="l">The ordered list.</param>
/// <param name="ord">INCREASING/DECREASING</param>
/// <returns>Return an ordered list.</returns>
list insord(TYPE_LIST el, list l, int ord);

/// <summary>
/// Merge two lists. Be careful, if you want to hang the second list to the first use instead append(list l1, list l2).
/// </summary>
/// <param name="l1"></param>
/// <param name="l2"></param>
/// <returns>l1+l2</returns>
list mergeList(list l1, list l2);

/// <summary>
/// Return the list of the elements shared by the two lists.
/// </summary>
/// <param name="l1"></param>
/// <param name="l2"></param>
/// <returns></returns>
list intersect(list l1, list l2);

/// <summary>
/// Return a list where all the elements that l1 has in common with l2 are deleted.
/// </summary>
/// <param name="l1"></param>
/// <param name="l2"></param>
/// <returns></returns>
list diff(list l1, list l2);

/// <summary>
/// Deallocate the memory of l1.
/// </summary>
/// <param name="l"></param>
void freeList(list l);

#endif // !LIST
