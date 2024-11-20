#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构体定义
typedef struct TreeNode {
    int data;                     // 结点数据
    struct TreeNode *left;        // 左子树
    struct TreeNode *right;       // 右子树
} TreeNode;

int countDegreeOneNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    printf("Visiting node with data: %d\n", root->data); // 调试输出
    int count = 0;
    // 判断当前结点是否是度为1
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        count = 1;
    }
    // 递归左右子树
    return count + countDegreeOneNodes(root->left) + countDegreeOneNodes(root->right);
}

int getTreeHeight(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    printf("Calculating height for node with data: %d\n", root->data); // 调试输出
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

TreeNode *findNode(TreeNode *root, int x) {
    if (root == NULL) {
        return NULL;
    }
    printf("Checking node with data: %d\n", root->data); // 调试输出
    if (root->data == x) {
        return root;
    }
    TreeNode *found = findNode(root->left, x);
    if (found != NULL) {
        return found;
    }
    return findNode(root->right, x);
}

int main() {
    // 创建简单的二叉树
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    if (root == NULL) {
        printf("Memory allocation failed for root\n");
        return -1;
    }
    root->data = 1;
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    if (root->left == NULL) {
        printf("Memory allocation failed for root->left\n");
        free(root);
        return -1;
    }
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = (TreeNode *)malloc(sizeof(TreeNode));
    if (root->left->right == NULL) {
        printf("Memory allocation failed for root->left->right\n");
        free(root->left);
        free(root);
        return -1;
    }
    root->left->right->data = 4;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    if (root->right == NULL) {
        printf("Memory allocation failed for root->right\n");
        free(root->left->right);
        free(root->left);
        free(root);
        return -1;
    }
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Tree created successfully\n");

    // 求度为1的结点数
    printf("Degree 1 nodes: %d\n", countDegreeOneNodes(root));

    // 求树的高度
    printf("Tree height: %d\n", getTreeHeight(root));

    // 查找值为4的结点
    TreeNode *foundNode = findNode(root, 4);
    if (foundNode != NULL) {
        printf("Node with value 4 found at address: %p\n", (void *)foundNode);
    } else {
        printf("Node with value 4 not found.\n");
    }

    // 释放内存
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
