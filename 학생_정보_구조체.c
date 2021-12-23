#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int number;
    char name[10];
    double grade;
};

int main(void)
{
    struct student s;
    s.number = 20211203;
    strcpy(s.name, "신민수");
    s.grade = 4.5;
    printf("%s님의 학점은 %.1f입니다. \n", s.name, s.grade);
    return 0;
}