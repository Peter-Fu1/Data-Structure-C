#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点数据类型
typedef int datatype;

// 定义二叉树节点和指针类型
typedef struct TreeNode *pointer;
typedef struct TreeNode {
    int data;
    pointer left;
    pointer right;
} TreeNode, *pointer;

typedef pointer biTree;

// 计算度为1的节点数
int countDegreeOneNodes(biTree root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        count = 1;
    }
    return count + countDegreeOneNodes(root->left) + countDegreeOneNodes(root->right);
}

// 计算二叉树高度
int getTreeHeight(biTree root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 查找值为x的节点
pointer findNode(biTree root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x) {
        return root;
    }
    pointer found = findNode(root->left, x);
    if (found != NULL) {
        return found;
    }
    return findNode(root->right, x);
}

// 释放二叉树内存
void freeTree(biTree root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // 创建一个二叉树
    biTree root = (pointer)malloc(sizeof(TreeNode));
    root->data = 1;

    // 创建左子树
    root->left = (pointer)malloc(sizeof(TreeNode));
    root->left->data = 2;
    root->left->left = NULL;

    root->left->right = (pointer)malloc(sizeof(TreeNode));

    root->left->right->data = 4;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    // 创建右子树
    root->right = (pointer)malloc(sizeof(TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Tree created successfully\n");

    // 求度为1的节点数
    printf("Degree 1 nodes: %d\n", countDegreeOneNodes(root));

    // 求树的高度
    printf("Tree height: %d\n", getTreeHeight(root));

    // 查找值为4的节点
    pointer foundNode = findNode(root, 4);

    // 释放内存
    freeTree(root);

    return 0;
}
