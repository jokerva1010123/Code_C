#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MIN 0.0000001

int check(double xa, double xb, double xc, double ya, double yb, double yc);

int main(void)
{
    double xa, xb, xc, ya, yb, yc;
    double s;
    if (scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc) == 6 && check(xa, xb, xc, ya, yb, yc))
    {
        s = fabs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya)) / 2;
        printf("%lf", s);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

int check(double xa, double xb, double xc, double ya, double yb, double yc)
{
    if ((fabs(xa - xb) > MIN || fabs(ya - yb) > MIN) && (fabs(xa - xc) > MIN || fabs(ya - yc) > MIN) && (fabs(xb - xc) > MIN || fabs(yb - yc) > MIN))
        if (fabs((xa - xb) * (ya - yc) - (ya - yb) * (xa - xc)) > MIN)
            return 1;
    return 0;
}