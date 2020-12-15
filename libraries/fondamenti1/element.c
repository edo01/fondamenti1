#include "Element.h"

boolean isEqual(Element el, Element el2) {
	return el == el2;
}

typeCompare compareTo_el(Element el, Element el2) {
	typeCompare result;
	if (el == el2) result = equal;
	else if (el > el2) result = more;
	else result = less;
	return result;
}

void put(Element el, Element* dest) {
	*dest = el;
}

void print_el(Element el) {
	printf("%d", el);
}

Element input_el() {
	Element a;
	scanf_s("%d\n", &a);
	return a;
}
