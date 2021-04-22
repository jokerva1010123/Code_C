#include<stdio.h>
#include<stdlib.h>

void bit2(unsigned int a);

int main()
{
    unsigned int a, b, c, d;
    int r = scanf("%u %u %u %u", &a, &b, &c, &d);
    if (r == 4 && (0 <= a && a <= 255) && (0 <= b && b <= 255) && (0 <= c && c <= 255) && (0 <= d && d <= 255))
    {
        printf("Result: ");
        bit2(a);
        bit2(b);
        bit2(c);
        bit2(d);
        printf(" ");
        printf("%u %u %u %u", a, b, c, d);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Error: Input error");
        return -1;
    }
}

void bit2(unsigned int a)
{
    for (int x = 7; x >= 0; x--)
        printf("%d", (a >> x) & 1);
}