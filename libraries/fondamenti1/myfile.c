/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/

#include "myfile.h"

FILE* openFile(char* fileName, char* mode) {
	FILE* f = NULL;
	if (fopen_s(&f, fileName, mode) != 0) {
		printf("cannot open file %s", fileName);
		return NULL;
	}
	return f;
}

int readField(char buffer[], int dim, char sep, FILE* f) {
	int count = 0;
	char input = fgetc(f);
	while (count < dim - 1 && input != '\n' && input!=sep && input!=EOF) {
		buffer[count] = input;
		input = fgetc(f);
		count++;
	}
	buffer[count] = '\0';
	if (input == '\n') return CR_C;
	else if (input == EOF) return EOF_C;
	else return SEP_C;
}



// CR is considered a separating char
int readField_ignoreChars(char buffer[], int dim, char ignoreChars[], int dimIgnore, char sep[], int dimSep, FILE* f) {
	int count = 0;
	char input = fgetc(f);
	while (count < dim - 1 && input != '\n' && !findChar(input, sep, dimSep) && input != EOF) {
		
		if (!findChar(input, ignoreChars, dimIgnore)) {
			buffer[count] = input;
			count++;
		}
		input = fgetc(f);
	}
	buffer[count] = '\0';
	if (input == '\n') return CR_C;
	else if (input == EOF) return EOF_C;
	else return SEP_C;
}