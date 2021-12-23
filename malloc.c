#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    pi = (int *)malloc(sizeof(int)); // malloc = 메모리를 할당해라. sizeof(int) 인트형의 크기만큼 할당. 숫자 4를 넣어도된다.
    if(pi==NULL)
    {
        printf("동적 메모리 할당에 실패했습니다.\n");
        exit(1);
    }
    *pi = 100;
    printf("%d\n", *pi);
    free(pi);
    return 0;
}