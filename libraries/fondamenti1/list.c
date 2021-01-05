/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include "list.h"

//head is the first element of the list
list emptyList() {
	return NULL;
}

boolean empty(list l) {
	return l == NULL;
}

TYPE_LIST head(list l) {
	if (empty(l)) exit(BAD_OPERATION_ON_EMPTY_LIST);
	return l->value;
}

list tail(list l) {
	if (empty(l)) exit(BAD_OPERATION_ON_EMPTY_LIST);
	else return l->next;
}

list cons(TYPE_LIST e, list l) {
	list new = (list) malloc(sizeof(item));
	if (new == NULL) exit(BAD_MALLOC_C);
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

boolean isMember(TYPE_LIST el, list l) {
	while (!empty(l)) {
		if (isEqual(el, l->value)) return TRUE;
		l = tail(l);
	}
	return FALSE;
}

int length(list l) {
	int count = 0;
	while (!empty(l)) {
		count++;
		l = tail(l);
	}
	return count;
}

list copy(list l) {
	if (empty(l)) return l;
	return cons(head(l), copy(tail(l)));
}

list append(list l, list l2) {
	if (empty(l)) return copy(l2); // Mello prefers return l2; structure sharing partial
	return cons(head(l), append(tail(l), l2));
}

list reverse(list l) {
	list reversed = emptyList();
	while (!empty(l)) {
		reversed = cons(head(l), reversed);
		l = tail(l);
	}
	return reversed;
}

list delete(TYPE_LIST el, list l) {
	if (empty(l)) return l;
	else if (!isEqual(head(l), el)) return cons(head(l), delete(el, tail(l)));
	else return tail(l);
}

list insord(TYPE_LIST el, list l, int ord) {
	if (empty(l)) return cons(el,l);
	else if (ord == INCREASING) {
		if (compareTo_el(el, head(l)) == lower) return cons(el, l);
		else return cons(head(l), insord(el, tail(l), ord));
	}
	else {
		if (compareTo_el(el, head(l)) == higher) return cons(el, l);
		else return cons(head(l), insord(el, tail(l), ord));
	}
}

//operazioni dell'insiemistica
list mergeList(list l1, list l2) {
	if (empty(l1)) return l2;
	else if (empty(l2))return l1;
	else {
		list u = append(l1, l2);
		list i = intersect(l1, l2);
		return diff(u, i);
	}
}

list intersect(list l1, list l2) {
	list intersection = emptyList();
	while (!empty(l1)) {
		if (isMember(head(l1), l2) && !isMember(head(l1), intersection)) {
			intersection = cons(head(l1), intersection);
		}
		l1 = tail(l1);
	}
	return intersection;
}

list diff(list l1, list l2) {
	list difference = emptyList();
	while (!empty(l1)) {
		if (!isMember(head(l1), l2) ) {
			difference = cons(head(l1), difference);
		}
		l1 = tail(l1);
	}
	return difference;
}

void freeList(list l) {
	if (empty(l))
		return;
	else {
		freeList(tail(l));
		free(l);
	}
}