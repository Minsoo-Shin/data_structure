#include <stdio.h>
#include <stdlib.h>

struct rbNode {
    int data;
    int color;
    struct rbNode* left;
    struct rbNode* right;
    struct rbNode* parent;
};

void inorder(struct rbNode* root) {
    //좌 -> root -> 우
    if (root == NULL) {
    inorder(root->left);

    print("%d ->", root->data );

    inorder(root->right);
    }
    return;
}



