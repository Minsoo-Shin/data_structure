#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// stack에 대한 struct 구성
typedef struct stack {
    // arr[SIZE], top
    int arr[SIZE];
    int top; 
} stack;


// init 함수 구성 ~!!!!!!!!!Q. init은 자동으로 실행되는건가? 
void init(stack *s)
{
    s -> top = -1;
}


// is_empty 함수 구성
int is_empty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

// is_full 함수 구성
int is_full(stack *s){
    if (s->top == SIZE - 1)
        return 1;
    return 0;
}

// push 기능함수 구현
int push(stack *s, int value)
{
    if (is_full(s))
    {
        printf("stack is full");
        exit(1);
    }
    s->arr[++(s->top)] = value;
    printf("pushed : %d\n", value);
}

// pop 기능함수 구현
int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--]; 
}
// peek 기능함수 구현
int peek(stack *s)
{
    if (is_empty(s) == 1)
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[s->top];
}
// main 함수 구현
int main(void)
{
    stack s;
    init(&s); 

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("%d\n", peek(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}
