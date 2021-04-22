#include <stdio.h>
#include <stdlib.h>
#define N 10

int read_n_m(size_t *n, size_t *m);
int read_matrix(size_t n, size_t m, int a[N][N]);
void chek_matrix(size_t n, size_t m, int a[N][N], int mini, int minj);
void write_matrix(int a[N][N], size_t n, size_t m);
void min_el(size_t n, size_t m, int a[N][N], int *mini, int *minj);
int sum(int a1);

int main()
{
    setbuf(stdout, NULL);
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
        if (err)
        {
            printf("Input error");
            return -1;
        }
        else
        {
            int mini = 0, minj = 0;
            min_el(n, m, a, &mini, &minj);
            chek_matrix(n, m, a, mini, minj);
            write_matrix(a, n - 1, m - 1);
        }
    }
    return EXIT_SUCCESS;
}
int read_n_m(size_t *n, size_t *m)
{
    int rc = scanf("%zu %zu", n, m);
    if (rc == 2)
    {
        if ((*n > 1) && (*n < 11) && (*m > 1) && (*m < 11))
            return 0;
        else
            return -1;
    }
    else
        return -1;
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
void min_el(size_t n, size_t m, int a[N][N], int *mini, int *minj)
{
    int s_min = sum(a[0][0]);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (s_min > sum(a[i][j]))
            {
                *mini = i;
                *minj = j;
                s_min = sum(a[i][j]);
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
void chek_matrix(size_t n, size_t m, int a[N][N], int mini, int minj)
{
    for (size_t i = mini; i < n - 1; i++)
        for (size_t j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    for (size_t j = minj; j < m - 1; j++)
        for (size_t i = 0; i < n; i++)
            a[i][j] = a[i][j + 1];
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
