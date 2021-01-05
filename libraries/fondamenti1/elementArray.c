#include "elementArray.h"

/*
	---------------------------------------------------------------------------------------------------------------------
	-------------------------------------------------- ARRAY ------------------------------------------------------------
	---------------------------------------------------------------------------------------------------------------------
*/

boolean isEqualArray(ElementArray el, ElementArray el2) {
	return el.id == el2.id;
}

typeCompare compareTo_elArray(ElementArray el, ElementArray el2) {
	typeCompare result;
	if (isEqualArray(el, el2)) result = equal;
	else if (el.id > el2.id) result = higher;
	else result = lower;
	return result;
}

void putArray(ElementArray el, ElementArray* dest) {
	*dest = el;
}

void print_elArray(ElementArray el) {
	printf("id: %d", el.id);
}