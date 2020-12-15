#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <assert.h>

//head is the first element of the list
list emptyList() {
	return NULL;
}

boolean empty(list l) {
	return l == NULL;
}

TYPE_LIST head(list l) {
	if (l == NULL) exit(-1);
	return l->value;
}

list tail(list l) {
	if (empty(l)) exit(1);
	else return l->next;
}

list cons(TYPE_LIST e, list l) {
	list new = (list) malloc(sizeof(item));
	if (new == NULL) exit(-1);
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

// why is better to create another list?
list append_c(list l, list l2) {
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
		if (compareTo_el(el, head(l)) == less) return cons(el, l);
		else return cons(head(l), insord(el, tail(l), ord));
	}
	else {
		if (compareTo_el(el, head(l)) == more) return cons(el, l);
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

void test_list_library() {
	//emptyList
	list l = emptyList();
	assert(empty(l));

	//cons
	l = cons(4, cons(2, cons(3, cons(4, cons(5, cons(6, l))))));

	//length
	assert(length(l) == 6);
	printf("length: OK\n");

	//head
	assert(head(l) == 4);

	//showList
	printf("showList\n");
	show_list(l);
	show_list(emptyList());
	printf("\nOK\n\n");

	//tail
	show_list(tail(l));
	assert(length(tail(l)) == 5);
	printf("\nTAIL: OK\n\n");

	//lastElement
	assert(lastElement(l)->value == 6);
	printf("last element: OK\n\n");


	//reverse
	printf("REVERSE\n");
	show_list(l);
	show_list(reverse(l));
	show_list(reverse(emptyList()));
	printf("OK\n\n");

	//copy
	printf("COPY\n");
	show_list(l);
	show_list(copy(l));
	show_list(copy(emptyList()));
	printf("OK\n\n");

	//append
	printf("APPEND\n");
	show_list(l);
	show_list(append(l, l));
	show_list(append(l, emptyList()));
	show_list(append(emptyList(), l));
	show_list(append(emptyList(), emptyList()));
	printf("OK\n\n");

	//delete
	printf("DELETE\n");
	show_list(l);
	show_list(delete(3, l));
	/*show_list(delete(NULL, l));
	show_list(delete(3, NULL));
	show_list(delete(emptyList(), emptyList()));*/
	printf("OK\n\n");

	//merge
	printf("MERGE\n");
	show_list(l);
	show_list(mergeList(l, cons(2, cons(14, emptyList()))));
	show_list(mergeList(NULL, l));
	show_list(mergeList(l, NULL));
	show_list(mergeList(l, l));
	show_list(mergeList(emptyList(), emptyList()));
	printf("NOT OK\n\n");

	//interserct
	printf("INTERSECT\n");
	show_list(l);
	show_list(intersect(l, cons(2, cons(14, emptyList()))));
	show_list(intersect(NULL, l));
	show_list(intersect(l, NULL));
	show_list(intersect(l, l));
	show_list(intersect(emptyList(), emptyList()));
	printf("OK\n");

	printf("DIFFERENCE\n");
	show_list(l);
	show_list(diff(l, cons(2, cons(14, emptyList()))));
	show_list(diff(NULL, l));
	show_list(diff(l, NULL));
	show_list(diff(append(l, l), l));
	show_list(diff(emptyList(), emptyList()));
	printf("OK\n");

	freeList(l);
}