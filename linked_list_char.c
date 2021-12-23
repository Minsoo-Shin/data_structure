#include <stdio.h>
#include <stdlib.h>

//NODE라는 구조체의 멤버는 *next, name가 있다. 
struct NODE {
    struct NODE *next; 
    char *name[20];
};

void addFirst(struct NODE *head, char *name) //어디에 무슨 name를 넣을거야
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode -> next = head -> next;
    newNode -> name = name;
    
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
    addFirst(head, "ahn");
    addFirst(head, "tom");
    addFirst(head, "willson");
    
    // removeFirst(head);

    struct NODE *curr = head -> next;
    while (curr != NULL)
    {
        printf("%s\n", curr -> name);
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