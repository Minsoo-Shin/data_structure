#include <stdio.h>
#include <limits.h>
#define NUMBER 5

int main(void)
{
    int i, max, min, index;
    max =0;
    index = 0;
    int array[NUMBER];
    for (i=0; i<5; i++)
    {
        scanf("%d", &array[i]);
        if (max < array[i])
        {
            max = array[i];
            index = i;
        }
    }
    printf("가장 큰 값은 %d. 그리고 그 원소는 %d번째 입니다.\n", max, 1+index);
    min = INT_MAX;
    for (i=0; i<NUMBER;i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            index = i;
        }
    }
    printf("가장 작은 값은 %d. 그리고 그 원소는 %d번째 입니다.\n", min, 1+index);
    return 0;
}