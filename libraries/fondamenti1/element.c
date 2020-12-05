#include "element.h"

#ifdef TEST

boolean isEqual(int el, int el2) {
	return el == el2;
}

typeCompare compareTo_el(int el, int el2) {
	typeCompare result;
	if (el == el2) result = equal;
	else if (el > el2) result = more;
	else result = less;
}

void put(int el, int* dest) {
	*dest = el;
}

void print_el(int el) {
	printf("%d", el);
}

int input() {
	int a;
	scanf_s("%d\n", &a);
	return a;
}
#endif // TEST
