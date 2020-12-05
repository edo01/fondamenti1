#pragma once

#include "element.h"

#define ELEMENT element

typedef struct list_element{ 
	ELEMENT value;
    struct list_element* next; 
} item;

typedef item* list;

//primitive
list emptyList();
boolean empty(list l);
ELEMENT head(list l);
list tail(list l);
list cons(ELEMENT e, list l);

item* lastElement(list l);

list reverse(list l);
list append(list l, list l2);
list append_c(list l, list l2);
int lenght(list l);
boolean isMember(ELEMENT el, list l);
void show_list(list l);
list copy(list l);
list delete(ELEMENT el, list l);
list insord(ELEMENT el, list l, int ord);
