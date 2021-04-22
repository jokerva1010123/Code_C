#include<stdio.h>
#include<math.h>

#define PI (4*atan(1.0))

int main(void)
{
    double a, b, temp;
    double phi;
    double h;
    double s;
    setbuf(stdout, NULL);
    printf("Input a, b, phi: ");
    scanf("%lf %lf", &a, &b);
    scanf("%lf", &phi);
    if (a > b) 
    {
        temp = a;
        a = b;
        b = temp;
    }
    phi = phi * PI / 180.0;
    h = (b - a) / 2.0 * tan(phi);
    s = (a + b) * h / 2.0;
    
    printf("Square: %.5lf", s);

    return 0;
}
