#include <stdio.h>
#include <stdlib.h>
#define NMAX 512
#define N 10

int read_n_m(size_t *n, size_t *m)
{
    if (scanf("%zu", n) != 1 || *n < 1 || *n > N)
        return EXIT_FAILURE;
    if (scanf("%zu", m) != 1 || *m < 1 || *m > N)
        return EXIT_FAILURE;
    if (*n != *m)
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

void change_matrix(int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < (n / 2); i++)
        for (size_t j = i; j <= (m - i - 1); j++)
        {
            int c = a[i][j];
            a[i][j] = a[n - i - 1][j];
            a[n - i - 1][j] = c;
        }
}

int main()
{
    int a[NMAX][NMAX];
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
    change_matrix(a, n, m);
    write_matrix(a, n, m);
    return EXIT_SUCCESS;
}