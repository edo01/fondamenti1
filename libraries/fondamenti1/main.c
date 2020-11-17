#include <string.h>
#include <stdio.h>
#include "common.h"

void find_secret(char str[], char str2[]) {
	int i = 0, j = 0;
	while (str[i] != '\0' && str2[j] != '\0') {
		if (str[i] == str2[j]) {
			i++;
			str[i] = str[i] + 'a' - 'A'  ;
		}
		else i++;
	}
}
int main() {
	char str1[] = "mbaob";
	char str2[] = "bb";
	find_secret(str1, str2);
	printf("%s", str1);
	return 0;
}