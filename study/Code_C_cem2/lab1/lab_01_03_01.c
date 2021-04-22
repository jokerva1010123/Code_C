#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    double v1, v2;
    float t1, t2;
    double v;
    float t;

    scanf("%lf %f", &v1, &t1);
    scanf("%lf %f", &v2, &t2);

    v = v1 + v2;
    t = (t1 * v1 + t2 * v2) / v;

    printf("%lf %f", v, t);

    return EXIT_SUCCESS;
}