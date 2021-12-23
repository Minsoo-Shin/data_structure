#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *pc = NULL;
    int i = 0;
    pc = (char *)malloc(100* sizeof(char));
    if(pc==NULL)
    {
        printf("동적 메모리 할당에 실패했습니다\n");
        exit(1);
    }
    return 0;
}