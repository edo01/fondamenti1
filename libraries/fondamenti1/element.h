#pragma once

#include <stdio.h>

//before the exam remember to toggle this
#define TEST

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef enum { more, less, equal } typeCompare;


// EVERY NEW TYPE HAS THIS FUNCTIONS
#ifdef TEST

boolean isEqual(int el, int el2);
typeCompare compareTo_el(int el, int el2);
void put(int el, int* dest);

void print_el(int el1);
#endif // TEST
