#include <stdio.h>
#include <stdlib.h>
#define N 10

int read_n_m(size_t *n, size_t *m);
int read_matrix(size_t n, size_t m, int a[N][N]);
void write_matrix(int a[N][N], size_t n, size_t m);
void min_el(size_t n, size_t m, int a[N][N]);
int max_el(int a[N][N], int jmax, size_t m);

int main()
{
    int a[N][N];
    size_t n, m;
    int err = read_n_m(&n, &m);
    if (err)
    {
        printf("Input error");
        return -1;
    }
    else
    {
        err = read_matrix(n, m, a);
        if (err != 0)
        {
            printf("Input error");
            return -1;
        }
        else
        {
            min_el(n, m, a);
            write_matrix(a, n, m);
        }
    }
    return EXIT_SUCCESS;
}
int read_n_m(size_t *n, size_t *m)
{
    int rc = scanf("%zu%zu", n, m);
    if (rc == 2)
    {
        if ((*n > 0) && (*n < 11) && (*m > 0) && (*m < 11))
            return EXIT_SUCCESS;
        else
            return EXIT_FAILURE;
    }
    else
        return EXIT_FAILURE;
}
int read_matrix(size_t n, size_t m, int a[N][N])
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return EXIT_FAILURE;
        }
    return EXIT_SUCCESS;
}
void min_el(size_t n, size_t m, int a[N][N])
{
    for (size_t i = 0; i < n; i++)
    {
        int jmax = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (max_el(a, j, m) > max_el(a, jmax, m))
                jmax = j;
        }
        for (size_t j = 0; j < m; j++)
        {
            int buf = a[jmax][j];
            for (size_t k = jmax; k > i; k--)
                a[k][j] = a[k - 1][j];
            a[i][j] = buf;
        }
    }
}
int max_el(int a[N][N], int jmax, size_t m)
{
    int max_a = a[jmax][0];
    for (size_t i = 0; i < m; i++)
        if (a[jmax][i] > max_a)
            max_a = a[jmax][i];
    return max_a;
}
void write_matrix(int a[N][N], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}