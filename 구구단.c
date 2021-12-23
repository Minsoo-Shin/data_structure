#include <stdio.h>

int main(void)
{
    int num, i;
    printf("정수를 입력하시오 : ");
    scanf("%d", &num);
    for (i = 1; i <= 9; i++)
    {
        printf("%d X %d = %d\n", num, i, num*i);
    }
}