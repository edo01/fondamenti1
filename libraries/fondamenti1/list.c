#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list emptyList() {
	return NULL;
}

boolean empty(list l) {
	return l == NULL;
}

ELEMENT head(list l) {
	if (l == NULL) exit(-1);
	return l->value;
}

list tail(list l) {
	if (empty(l)) exit(1);
	else return l->next;
}

list cons(ELEMENT e, list l) {
	list new = (list) malloc(sizeof(item));
	// GENERALIZZARE QUESTO
	put(e, &(new->value));
	new->next = l;
	return new;
}

item* lastElement(list l) {
	if (empty(l)) return l;
	while (!empty(l->next)) {
		l = tail(l);
	}
	return l;
}

void show_list(list l) {
	printf("[");
	while (!empty(l)) {
		print_el(l->value);
		l = tail(l);
		if (!empty(l))printf(",");
	}
	printf("]");
}

boolean isMember(ELEMENT el, list l) {
	while (!empty(l)) {
		if (isEqual(el, l->value)) return TRUE;
		l = tail(l);
	}
	return FALSE;
}

int lenght(list l) {
	int count = 0;
	while (!empty(l)) {
		count++;
		l = tail(l);
	}
	return count;
}

// why is better to create another list?
list append(list l, list l2) {
	item* last = lastElement(l);
	last->next = l2;
	return l;
}

//this doesn't work
list copy(list l) {
	if (empty(l)) return l;
	return cons(head(l), copy(tail(l)));
}

//also this
list append_c(list l, list l2) {
	if (empty(l)) return copy(l2); // Mello prefers return l2; structure sharing parziale
	return cons(head(l), append_c(tail(l), l2));
}

list reverse(list l) {
	list reversed = emptyList();
	while (!empty(l)) {
		reversed = cons(head(l), reversed);
		l = tail(l);
	}
	return reversed;
}