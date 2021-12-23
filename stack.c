#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 // SIZE 변수 선언 가능

typedef struct stack { 
    // arr[SIZE], top
    int arr[SIZE];
    int top; 
} stack;

void init(stack *s)
{
    s->top = -1; //배열은 index 0부터 시작
}

int is_empty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}
//full : return 1
// !full : return 0
int is_full(stack *s)
{
    if(s->top == SIZE -1)
        return 1;
    return 0;
}

void push(stack *s, int value)
{
    if(is_full(s))
    {
        printf("stack is full");
        exit(1);
    }
    printf("pushed: %d\n", value);
    s-> arr[++(s->top)] = value;
}

int pop(stack *s)
{
    if(is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int peek(stack *s)
{
    if(is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[(s->top)];
}

int main()
{
    stack s;
    init(&s); //stack이 초기화됨.

    push(&s, 300);
    push(&s, 200);
    push(&s, 100);

    printf("peek: %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("%d", s.top);

    // printf("\npop: %d\n",pop(&s));
    return 0;
}