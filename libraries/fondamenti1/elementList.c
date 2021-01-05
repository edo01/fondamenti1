/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include "elementList.h"

/*	
	---------------------------------------------------------------------------------------------------------------------
	--------------------------------------------------  LIST ------------------------------------------------------------
	---------------------------------------------------------------------------------------------------------------------
*/

boolean isEqual(Element el, Element el2) {
	return el.id == el2.id;
}

typeCompare compareTo_el(Element el, Element el2) {
	typeCompare result;
	if (isEqual(el, el2)) result = equal;
	else if (el.id > el2.id) result = higher;
	else result = lower;
	return result;
}

void put(Element el, Element* dest) {
	*dest = el;
}

void print_el(Element el) {
	printf("id: %d", el.id);
}