#include<stdio.h>
#include<stdlib.h>
#define N 10
#define NMAX 512

void spiral_fill(size_t n, size_t m, int a[NMAX][NMAX])
{
    int val = 1;
    int k = 0, l = 0;
    while (k < m && l < n)
    {
        for (int i = l; i < n; ++i)
            a[k][i] = val ++;
        k ++;
        for (int i = k; i < m; ++i)
            a[i][n - 1] = val++;
        n--;
        if (k < m)
        {
            for (int i = n - 1; i >= l; --i)
                a[m - 1][i] = val++;
            m--;
        }
        if (l < n)
        {
            for (int i = m - 1; i >= k; --i)
                a[i][l] = val++;
            l++;
        }
    }
}

void print(int a[NMAX][NMAX], size_t r, size_t c)
{
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main(void)
{
    size_t n, m;
    int a[NMAX][NMAX];
    if (scanf("%zu", &n) != 1 || n < 1 || n > N)
    {
        printf("Input error");
        return -1;
    }
    if (scanf("%zu", &m) != 1 || m < 1 || m > N)
    {
        printf("Input error");
        return -1;
    }
    if (n != m)
    {
        printf("Input error");
        return -1;
    }
    spiral_fill(n, m, a);
    print(a, n, m);
    return EXIT_SUCCESS;
}