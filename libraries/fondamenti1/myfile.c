#include "myfile.h"


//to test
int readField(char buffer[], int dim, char sep, FILE* f) {
	int count = 0;
	char input = fgetc(f);
	while (count < dim - 1 && input != '\n' && input!=sep && input!=EOF) {
		buffer[count] = input;
		input = fgetc(f);
		count++;
	}
	buffer[count] = '\0';
	return input;
}