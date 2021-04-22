#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double calc(double x, double eps);

int main(void)
{
    double x, eps;
    int rc;
    rc = scanf("%lf %lf", &x, &eps);
    if ((rc == 2) && (1 - eps > 0.0000001) && (eps > 0))
    {
        double rezs = calc(x, eps);
        printf("%lf\n", rezs);
        double rezf = sin(x);
        printf("%lf\n", rezf);
        double erro, errp;
        erro = fabs(rezf - rezs);
        errp = erro / rezf;
        printf("%lf\n", fabs(erro));
        printf("%lf\n", fabs(errp));
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

double calc(double x, double eps)
{
    double t, t1, rezs = 0;
    int n = 1;
    long long k = 1;
    t = x;
    rezs = x;
    t1 = t / k;
    while (fabs(t1) > eps)
    {
        n += 1;
        t = t * (-1) * x * x;
        k = k * (2 * n - 2) * (2 * n - 1);
        t1 = t / k;
        rezs = rezs + t1;
    }
    return rezs;
}