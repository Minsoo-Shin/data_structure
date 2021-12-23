#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    int c;

    fp = fopen("input.txt", "r");
    {
        printf("파일 열기에 실패했습니다\n");
    }
}