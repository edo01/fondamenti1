#include "element.h"

boolean isEqual(element *el, element *el2) {
	return *el == *el2;
}

typeCompare compareTo_el(element* el, element* el2) {
	typeCompare result;
	if (*el == *el2) result = equal;
	else if (*el > *el2) result = more;
	else result = less;
}

void put(element el, element* dest) {
	*dest = el;
}

void print_el(element el) {
	printf("%d", el);
}

element input_el() {
	element a;
	scanf_s("%d\n", &a);
	return a;
}
