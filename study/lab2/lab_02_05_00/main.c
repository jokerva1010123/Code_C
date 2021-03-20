#include <stdio.h>
#include <stdlib.h>
#define N 10

int read(long long *pa, long long *pb);

int main()
{
    long long a[N];
    long long *pa = a;
    int n;
    setbuf(stdout, NULL);
    printf("Input N (integer) ");
    int rc = scanf("%d", &n);
    if (rc == 1)
    {
        long long res = -100000000;
        if ((n > 0) && (n < 11))
        {
            long long *pb;
            pb = pa + n;
            int fi = read(pa, pb);
            pb--;
            if (fi)
            {
                while (pa <= pb)
                {
                    if (res < (*pa) + (*pb))
                        res = (*pa) + (*pb);
                    pa ++;
                    pb--;
                }
                printf("Result: %lld", res);
                return EXIT_SUCCESS;
            } 
            else
            {
                printf("Input error");
                return -1;
            }
        }
        else
        {
            printf("Input error");
            return -1;
        }
    }
    else
    {
        printf("Input error");
        return -1;
    }
}
int read(long long *pa, long long *pb)
{
    int fi;
    int rc;
    fi = 1;
    long long s;
    for (; pa < pb;)
    {
        printf("Element of array ");
        rc = scanf("%lld", &s);
        if (rc == 1)
        {
            *pa = s;
            pa++;
        }
        else
        {
            fi = 0;
            break;
        }
    }
    return fi;
}