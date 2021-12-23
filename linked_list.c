#include <stdio.h>
#include <stdlib.h>

//NODE라는 구조체의 멤버는 *next, data가 있다. 
struct NODE {
    struct NODE *next; 
    int data;
};

void addFirst(struct NODE *head, int data) //어디에 무슨 data를 넣을거야
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode -> next = head -> next;
    newNode -> data = data;
    
    head -> next = newNode;
}

void removeFirst(struct NODE *head)
{
    // head -> next를 head의 다음다음노드로 가리키게 만들면 head의 다음 노드를 free할 수 없으니
    struct NODE *deleteNode = head -> next;
    head -> next = deleteNode -> next;

    free(deleteNode);
}

int main(void){
    // 포인터변수 head에 메모리 주소를 동적할당한다. 
    struct NODE *head = malloc(sizeof(struct NODE)); 
    // head의 next는 NULL로 초기화
    head -> next = NULL;
    
    //insert 구현
    addFirst(head, 10);
    addFirst(head, 20);
    addFirst(head, 30);
    
    removeFirst(head);
    removeFirst(head);

    struct NODE *curr = head -> next;
    while (curr != NULL)
    {
        printf("%d\n", curr -> data);
        curr = curr -> next;
    }

    curr = head -> next;
    while (curr != NULL)
    {
        struct NODE *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(head);
    return 0;
}