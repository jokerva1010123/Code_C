#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MIN 1e-6

double calc();

int main(void)
{
    double g;
    g = sin(calc());
    printf("%lf", g);
    return 0;
}

double calc()
{
    double x = 0.0;
    double g = 0.0;
    int n = 0;
    while (x >= -MIN)
    {
        scanf("%lf", &x);
        if (x < -MIN)
            break;
        n = n + 1;
        g = g + sqrt(x / n);
    }
    return g;
}