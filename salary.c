#include <stdio.h>
#define MONTHS 12

int main(void)
{
    double monthSalary = 100.5;
    printf("$ %.2f", monthSalary / MONTHS);
    return 0;
}