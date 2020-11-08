void scambia(double* a, double* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void fromMillisec(int millisec, int* mm, int* sec, int* min)
{
    *mm = millisec % 1000;
    *sec = millisec / 1000;
    *min = *sec / 60;
}