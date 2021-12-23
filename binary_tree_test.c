#include <stdio.h>
#include <stdlib.h>

//구조체를 설계
struct node 
{
    int key;
    struct node *left;
    struct node *right;
};
//newNode 설계 
struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
    if (root != NULL){
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%d -> ", root -> key);

        // Traverse right
        inorder(root->right);
    }
}

//insert 설계
struct node* insert(struct node* root , int key) {
    // root null일 경우, 그냥 root 반환
    if (root == NULL)
        return newNode(key);
    // root->key가 찾는 key보다 작다면 오른쪽 루트로 재귀
    if (key < root->key)
        root->left = insert(root->left, key);
    // root->key가 찾는 key보다 크다면 왼쪽 루트로 재귀
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}


//delete를 위한 minValue 설계
struct node* minValue(struct node* root) {
    struct node* temp = root;
    if (temp->left != NULL)
        temp = temp->left;
    return temp;
}

//delete 설계
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;
    // key < root->key 일떄, 왼쪽가서 delete
    if (key < root->key) 
        root->left = deleteNode(root->left, key);
    // key > root->key 일때, 오른쪽가서 delete
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    // key == root->key 일때.
    else {
        //root node가 한쪽만 있을때
        //root->right == NULL 일때
        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            root = temp;
            return root;    
        } else if (root->left == NULL) {   //root->left == NULL 일때
            struct node* temp = root->right;
            free(root);
            root = temp;
            return root;
        } 
        
        //root node가 두쪽 다 있을때
        root->key = minValue(root->right)->key;
        root->right = deleteNode(root->right, root->key);
    }

    return root;
}

// Driver code
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Inorder traversal: ");
  inorder(root);

  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inorder(root);
}
// //int main
// int main(void) {
//     int n;
//     scanf("몇 개의 노드를 입력할건가요? %d", &n);
//     struct node* root;
//     for (int i = 0; i < n; i++) {
//         int a;
//         scanf("노드의 key값을 입력하시오 : %d", &a);
//         root = insert_node(root, a);
//     }

//     inorder(root);
//     int key;
//     scanf("삭제할 노드의 키를 입려하시오 : %d", &key);
//     deleteNode(root, key);
//     inorder(root);

//     return 0;
// }