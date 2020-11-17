#include <string.h>
#include "common.h"

boolean mycmp(char str1[], int start, int last, char str2[]) {
	int dim1 = last - start;
	int dim2 = strlen(str2);
	if (dim1 != dim2) return FALSE;
	for (int i = 0; i < dim1; i++) {
		if (str1[start + i] != str2[i]) return FALSE;
	}
	return TRUE;
}

int find_count(char str[], char substr[]) {
	//sensibile al buffer overrun
	int dimSTR = strlen(str);
	int dimSubSTR = strlen(substr);
	int count = 0;
	for (int i = 0; i < dimSTR - dimSubSTR + 1; i++) {
		if (mycmp(str, i, i + dimSubSTR, substr)) count++;
	}
	return count;
}