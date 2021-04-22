#include<stdio.h>

int main(void)
{
    int num;
    int enter, floor;

    scanf("%d", &num);
    enter = (num + 35) / 36;
    num = num - (enter - 1) * 36;
    floor = (num + 3) / 4;

    printf("%d ", enter);
    printf("%d\n", floor);
    return 0;
}