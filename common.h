#define BOOLEAN int
#define TRUE 1
#define FALSE 0

/*
#define _CRT_SECURE_NO_DEPRECATE // Sono direttive al     pre-compilatore, per poter utilizzare funzioni depre    cate
//#define _CRT_SECURE_NO_WARNINGS
*/

void scambia(double *a, double *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void fromMillisec(int millisec, int *mm, int *sec, int *min)
{
    *mm = millisec % 1000;
    *sec = millisec / 1000;
    *min = *sec / 60;
}