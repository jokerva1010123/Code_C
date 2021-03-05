#include<stdio.h>
#include<stdlib.h>

int calc(int a, int d);

int main(void)
{
    int a;
    int d;
    int q;
    if ((scanf("%d %d", &a, &d) == 2) && (a > 0) && (d > 0))
    {
        q = calc(a, d);
        printf("%d\n%d", q, a - d * q);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

int calc(int a, int d)
{
    int l = 0, r = a + 1, mid;
    while (r - l> 1)
    {
        mid = (r + l) / 2;
        if (mid * d > a)
            r = mid;
        else 
            l = mid;
    }
    return l;
}