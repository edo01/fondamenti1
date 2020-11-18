#define TYPE int

void invert(TYPE *a, TYPE *b)
{
    TYPE t = *a;
    *a = *b;
    *b = t;
}