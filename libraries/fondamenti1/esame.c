/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include "esame.h"


/*---------------------------------------------------------------------
-------------------------------ARRAY-----------------------------------
-----------------------------------------------------------------------
*/

int leggiElementArray(FILE* f, ElementArray* el) {
	int result;

	if (fscanf_s(f, "%d", &(el->id)) != 1) result = EOF_C;
	else if (fscanf_s(f, "%d", &(el->id)) != 1) result = BAD_FORMAT_C;
	else result = OK_C;
	return result;
}

//cambia ElementArray con il tipo che ti serve
ElementArray* leggiTuttiElementArray(char* fileName, int* dim) {
	FILE* f;
	ElementArray elemento;
	ElementArray* elementi;
	int count = 0, res;

	//apro il file in lettura
	if ((f = openFile(fileName, "rt")) == NULL) {
		*dim = 0;
		return NULL;
	}

	//conto gli elementi nel file
	do {
		res = leggiElementArray(f, &elemento);
		if (res == BAD_FORMAT_C) {
			printf("Errore! Formato del file sbagliato.");
			*dim = 0;
			return NULL;
		}
		else if (res == OK_C) count++;
	} while (res == OK_C);


	//alloco dinamicamente la memoria
	*dim = count;
	count = 0;
	elementi = (ElementArray*)malloc(sizeof(ElementArray) * (*dim));

	// controllo che sia stata allocata correttamente memoria per l'array
	if (elementi == NULL) {
		printf("Errore! Impossibile allocare memoria\n");
		*dim = 0;
		return NULL;
	}

	// riparto da capo
	rewind(f);

	//salvo i dati nell'array
	do {
		res = leggiElementArray(f, &elemento);
		if (res == BAD_FORMAT_C) {
			printf("Errore! Formato del file sbagliato.");
			*dim = 0;
			return NULL;
		}
		else if (res == OK_C) elementi[count++] = elemento;
	} while (res == OK_C);

	//chiudo il file
	fclose(f);

	return elementi;

}

/*---------------------------------------------------------------------
-------------------------------LIST------------------------------------
-----------------------------------------------------------------------
*/
int leggiElement(FILE* f, Element* el) {
	int result;

	if (fscanf_s(f, "%d", &(el->id)) != 1) result = EOF_C;
	else if (fscanf_s(f, "%d", &(el->id)) != 1) result = BAD_FORMAT_C;
	else result = OK_C;
	return result;
}

list leggiTuttiElement(char* fileName) {
	FILE* f;
	list l = emptyList();
	Element elemento;
	boolean flag = TRUE;
	int res;

	//apro il file in lettura
	if ((f = openFile(fileName, "rt")) == NULL) {
		return emptyList();
	}

	//leggo e salvo i dati presenti nel file nella lista
	do {
		res = leggiElement(f, &elemento);
		if (res == OK_C)  l = cons(elemento, l);
		else if (res == BAD_FORMAT_C) {
			printf("Errore, formato del file sbagliato\n");
			return emptyList();
		}
		else flag = FALSE;
	} while (flag);

	fclose(f);
	return l;
}