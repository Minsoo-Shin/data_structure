#include <stdio.h>

int main(void)
{
    int x= 5;
    float y = 123456789.123456789;
    double z = 123456789.123456789;
    printf("x = %d\n", x);
    printf("y = %.2f\n", y);
    printf("z = %.2f\n", z);
    

    char a = 1;
    short b;
    int c;
    long d;
    long long e;

    float f;
    double g;
    long double h;

    printf("char의 자료형 크기는 %d\n", sizeof(a));
    printf("short의 자료형 크기는 %d\n", sizeof(b));
    printf("int의 자료형 크기는 %d\n", sizeof(c));
    printf("long의 자료형 크기는 %d\n", sizeof(d));
    printf("long long의 자료형 크기는 %d\n", sizeof(e));
    printf("float의 자료형 크기는 %d\n", sizeof(f));
    printf("double의 자료형 크기는 %d\n", sizeof(g));
    printf("long double의 자료형 크기는 %d\n", sizeof(h));

    return 0;
    
}
