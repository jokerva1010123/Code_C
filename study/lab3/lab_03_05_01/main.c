#include <stdio.h>
#include <stdlib.h>
#define N 10
#define NN N*N+1
#define NMAX 512

int read_n_m(size_t *n, size_t *m)
{
    if (scanf("%zu", n) != 1 || *n < 1 || *n > N)
        return EXIT_FAILURE;
    if (scanf("%zu", m) != 1 || *m < 1 || *m > N)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int read_matrix(size_t n, size_t m, int a[NMAX][NMAX])
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void write_matrix(int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int sum(int a1)
{
    int s = 0;
    if (a1 < 0)
        a1 = (-1) * a1;
    while (a1)
    {
        s += (a1 % 10);
        a1 /= 10;
    }
    return s;
}

void arr(int b[NN], int a[NMAX][NMAX], size_t n, size_t m, int *k)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (sum(a[i][j]) > 10)
            {
                b[*k] = a[i][j];
                *k = *k + 1;
            }
}

void left_arr(int b[NN], int k)
{
    for (int i = 0; i < 3; i++)
    {
        int c = b[0];
        for (int j = 1; j < k; j++)
            b[j - 1] = b[j];
        b[k - 1] = c;
    }
}

void new_matrix(int a[NMAX][NMAX], int b[NN], size_t n, size_t m)
{
    int p = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (sum(a[i][j]) > 10)
            {
                a[i][j] = b[p];
                p++;
            }
}

int main()
{
    int a[NMAX][NMAX];
    int b[NN];
    size_t n, m;
    if (read_n_m(&n, &m))
    {
        printf("Input error");
        return -1;
    }
    if (read_matrix(n, m, a))
    {
        printf("Input error");
        return -1;
    }
    int k = 0;
    arr(b, a, n, m, &k);
    if (!k)
    {
        printf("Input error");
        return -1;
    }
    else
    {
        left_arr(b, k);
        new_matrix(a, b, n, m);
        write_matrix(a, n, m);
    }
    return EXIT_SUCCESS;
}