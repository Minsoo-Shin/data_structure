#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
int main(void)
{
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf("%d\n", x);
    printf("%d\n", y);
    return 0;
}