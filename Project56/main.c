#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    int is_thread;
} TreeNode;

// (��� ���� �κ��� �״�� �ΰ�, parent �Լ��� �����մϴ�)

TreeNode n1 = { 4,NULL,NULL,1 };
TreeNode n2 = { 5,NULL,NULL,1 };
TreeNode n3 = { 3,&n1,&n2,0 };
TreeNode n4 = { 6,NULL,NULL,1 };
TreeNode n5 = { 2,&n3,&n4,0 };
TreeNode n6 = { 8,NULL,NULL,1 };
TreeNode n7 = { 10,NULL,NULL,1 };
TreeNode n8 = { 11,NULL,NULL,0 };
TreeNode n9 = { 9,&n7,&n8,0 };
TreeNode n10 = { 7,&n6,&n9,0 };
TreeNode n11 = { 1,&n5,&n10,0 };
TreeNode* exp = &n11;

TreeNode* find_succesor(TreeNode* p) {
    TreeNode* q = p->right;
    if (q == NULL || p->is_thread == TRUE)
        return q;
    while (q->left != NULL) q = q->left;
    return q;
}
void thread_inorder(TreeNode* t) {
    TreeNode* q;
    q = t;
    while (q->left) q = q->left;
    do {
        printf("%d ", q->data);
        q = find_succesor(q);

    } while (q);

}
// Ư�� ����� �θ� ��带 ã�Ƽ� ��ȯ�ϴ� parent �Լ� ����
TreeNode* parent(TreeNode* root, TreeNode* child) {
    if (root == NULL || child == NULL) {
        return NULL;
    }

    if ((root->left == child && root->left->is_thread == TRUE) || root->right == child) {
        return root;
    }

    TreeNode* left_parent = parent(root->left, child);
    if (left_parent != NULL) {
        return left_parent;
    }

    return parent(root->right, child);
}

int main(void) {
    n1.right = &n3;
    n2.right = &n5;
    n4.right = &n11;
    n6.right = &n10;
    n7.right = &n9;

    printf("1. ���� ��ȸ ���\n");
    thread_inorder(exp);
    printf("\n\n");

    printf("2. Node 4�� �θ�: ");
    TreeNode* parent4 = parent(exp, &n1);
    if (parent4 != NULL) {
        printf("%d\n", parent4->data);
    }
    else {
        printf("�θ� ����\n");
    }

    printf("3. Node 5�� �θ�: ");
    TreeNode* parent5 = parent(exp, &n2);
    if (parent5 != NULL) {
        printf("%d\n", parent5->data);
    }
    else {
        printf("�θ� ����\n");
    }

    printf("4. Node 6�� �θ�: ");
    TreeNode* parent6 = parent(exp, &n4);
    if (parent6 != NULL) {
        printf("%d\n", parent6->data);
    }
    else {
        printf("�θ� ����\n");
    }

    return 0;
}