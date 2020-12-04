#pragma once

#pragma warning(disable:4996)

#include <string.h>
#include "element.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/*
int conc(char A[], char B[], char C[], int dimC) {
	int result;
	if (dimC < (strlen(A) + strlen(B) + 1)) result = ERROR;
	else {
		strcpy_s(C, A);
		strcpy_s(C + strlen(A), B,);
		result = strlen(strlen(A) + strlen(B));
	}
	return result;
}
typedef struct {
	char nome[11], cognome[16];
	int iscritti;
} insegnamento;

#define DIM 10

typedef struct {
	char codice[4];
	float new_price, old_price;
} prodotto;


void lettura(prodotto products[], int dim, int *logic) {
	*logic = 0;
	for(int i = 0; i<DIM; i++){
		printf("inserisci il codice del prodotto\n");
		scanf_s("%s", products[i].codice, 4);
		if (strcmp_s(products[i].codice, "finito")) return;
		printf("Inserisci il vecchio prezzo del prodotto\n");
		scanf_s("%f", products[i].old_price);
		printf("Inserisci il nuovo prezzo del prodotto\n");
		scanf_s("%f", products[i].new_price);
		(*logic)++;
	}
}

void maxItem() {
	prodotto p[DIM];
	int logic;
	lettura(p, DIM, &logic);
	for (int i = 0; i < logic; i++) {
		float inflazione = ((p[i].new_price / p[i].old_price) - 1) * 100;
		printf("l'inflazione per %s è %f", p[i].codice, inflazione);
	}
}

typedef struct {
	char nome[30];
	int posto;
} booking;

#define FINE 0
#define STAMPA -1
#define OK 1

int leggi(booking *b) {
	char nome[31];
	printf("inserisci il nome del passeggero?\n");
	scanf_s("%s", nome, 31);
	if (strcmp(nome, "fine")) return FINE;
	if (strcmp(nome, "stampa")) return STAMPA;
	//strcpy(b->nome, nome);
	pritnf("inserisci posto:");
	scanf_s("%d", b->posto);

	return OK;
}

boolean assegna(booking list[], int dim, int* lengthList, char* name, int pref) {
	for (int i = 0; i < lengthList - 1; i++) {
		if (list[i].posto == pref) {
			(*lengthList)--;
			return FALSE;
		}
	}
	return TRUE;
}

void stampa(booking b[], int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%s posto %d\n", b[i].nome, b[i].posto);
	}
}
void interfaccia() {
	booking bookings[DIM];
	int dim = 0;
	for (int i = 0; i < DIM; i++) {
		int result = leggi(&bookings[i]);
		if (result == FINE) {

		}
		else if (result == STAMPA) {
			stampa(bookings, dim);
		}
		else {
			dim++;
			if (assegna(bookings, DIM, dim, bookings[i].nome, bookings[i].posto)) i--;
		}
	}
}

void riempi_matrix(float misures[][12], int dimi, int dimj){
	for (int i = 0; i < dimi; i++) {
		for (int j = 0; j < dimj; j++) {
			misures[i][j] = rand() % 3 + 18;
		}
	}
}

void stazione() {
	int aprile[31][12], maggio[31][12];
	riempi_matrix(aprile, 31, 12);
	riempi_matrix(maggio, 31, 12);
}
*/

#define DIM_SQUARE 3
#define MAGIC_CONSTANT 15


#define IS_NOT_A_SQUARE -1
#define IS_A_SQUARE 0

boolean isASquare(int square[][DIM_SQUARE]) {
	int count = 0;//how many times the number is present inside of the square
	for (int i = 0; i < DIM_SQUARE; i++) {
		for (int j = 0; j < DIM_SQUARE; j++) {
			if (square[i][j] < 1 && square[i][j]>(DIM_SQUARE*DIM_SQUARE)) return IS_NOT_A_SQUARE;
			for (int i2 = 0; i2 < DIM_SQUARE; i2++) {
				for (int j2 = 0; j2 < DIM_SQUARE; j2++) {
					if (square[i][j] == square[i2][j2]) count++;
					if (count > 1) return IS_NOT_A_SQUARE;
				}
			}
			count = 0;
		}
	}
	return IS_A_SQUARE;
}

#define SUM_OK 0
#define VERTICAL_ERR 1
#define HORIZZONTAL_ERR 2
#define OBLIQUE_ERR 3

int checkSum( int square[][DIM_SQUARE]) {
	int sum = 0;
	// horizzontal sum
	for (int i = 0; i < DIM_SQUARE; i ++) {
		for (int j = 0; j < DIM_SQUARE; j++) {
			sum += square[i][j];
		}
		if (sum != MAGIC_CONSTANT) return HORIZZONTAL_ERR;
		sum = 0;
	}

	// vertical sum
	for (int i = 0; i < DIM_SQUARE; i++) {
		for (int j = 0; j < DIM_SQUARE; j++) {
			sum += square[j][i];
		}
		if (sum != MAGIC_CONSTANT) return VERTICAL_ERR;
		sum = 0;
	}

	//oblique sum
	for (int i = 0; i < DIM_SQUARE; i++) {
		sum += square[i][i];
	}
	if (sum != MAGIC_CONSTANT) return OBLIQUE_ERR;
	
	return IS_A_SQUARE;
}

boolean isMagicSquare(int square[][DIM_SQUARE]) {
	if (isASquare(square) == IS_A_SQUARE) {
		return checkSum(square);
	} else return IS_NOT_A_SQUARE;
}



#define TYPE_FIND int

boolean compareTo_find_s(TYPE_FIND a, TYPE_FIND b) {
	return a == b;
}

boolean find_s(TYPE_FIND array[], int dim, TYPE_FIND el) {
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++)
	{
		if (compareTo_find_s(array[i], el)) found = TRUE;
	}
	return found;
}

void unusedNumbers(int used[], int logic, int *logicUnused, int unused[]) {
	int all[9] = { 1,2,3,4,5,6,7,8,9 };
	*logicUnused = 0;
	for (int i = 0; i < 9; i++) {
		if (!find_s(used, logic, all[i])) {
			unused[*logicUnused] = all[i];
			(*logicUnused)++;
		}
	}
}

void stampa(int square[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", square[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

boolean ramo(int square[][3], int last_R, int last_C, int used[], int logic) {
	int logicUnused, unused[9];
	unusedNumbers(used, logic, &logicUnused, unused);
	if (last_C == 2 && last_R == 2) {
		if (logicUnused != 1) exit(-1);
		square[2][2] = unused[0];
		stampa(square);
		if (isMagicSquare(square) == IS_A_SQUARE) return TRUE;
		else return FALSE;
	}
	
	int new_R = last_R, new_C = last_C;
	if ((new_C= (new_C + 1) %3) == 0) {
		new_R++;
	}

	for (int i = 0; i < logicUnused; i++) {
		square[last_R][last_C] = unused[i];
		used[logic] = unused[i];
		int debug = used[logic];
		logic++;
		if(ramo(square, new_R, new_C, used, logic)) return TRUE;
		logic--;
	}
	return FALSE;
}


void solveMagicSquare() {
	int square[3][3];
	int used[9] = { 0,0,0,0,0,0,0,0,0};
	int logic = 0;
	for (int i = 1; i <= 9; i++) {
		logic = 0;
		square[0][0] = i;
		used[logic] = i;
		logic = 1;
		if (ramo(square, 0, 1, used, logic)) return;
	}
}

typedef struct {
	float importo;
	unsigned int n;
} scontrino;


//errato
int scrivi(FILE* f, scontrino s) {
	int result = 0;
	if ((f = fopen("reg.dat", "wb")) != NULL) {
		result = fwrite(&s, sizeof(scontrino), 1, f);
		/*fwrite(&(s->importo),sizeof(float),1, f);
		fwrite(&(s->n), sizeof(unsigned int), 1, f);*/
		fclose(f);
	}
	return result;
}

int leggi(FILE* f, scontrino* s) {
	int result = 0;;
	if ((f = fopen("reg.dat", "rb")) != NULL) {
		result = fread(s, sizeof(scontrino), 1, f);
		fclose(f);
	}
	return result;
}

typedef struct {
	char nome[63];
	float apertura, chiusura;
	int giorno;
} azione;

int leggi_2(FILE* f, azione azioni[], int dim, char* nome) {
	int result = 0;
	
	for (int i = 0; i < dim; i++) {
		result = result + fscanf(f, "%s %f %f %d", azioni[i].nome, &(azioni[i].apertura), &(azioni[i].chiusura), &(azioni[i].giorno));
		if (strcmp(azioni[i].nome, nome)!=0) i--;
	}
	return result;
}
