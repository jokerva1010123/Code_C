#include <stdio.h>
#include <stdlib.h>
#define N 10
#define OK 0
#define ERR -1

void sortt(int a[], int n);

int main()
{
    int n = 0;
    int a[N];
    int s;
    int code = 0;
    while (scanf("%d", &s) == 1)
    {
        if (n == 10)
        {
            code = 100;
            break;            
        }
        a[n] = s;
        n += 1;
    }
    if (n == 0) 
        return EXIT_FAILURE;
    sortt(a, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    if (code == 100) 
        return 100;
    else
        return EXIT_SUCCESS;
}

void sortt(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
    }
}
