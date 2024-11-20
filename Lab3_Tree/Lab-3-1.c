#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct TreeNode *pointer;
typedef struct TreeNode{
    int data;
    pointer left;
    pointer right;
}TreeNode, *pointer;
typedef pointer biTree;

int countDegreeOneNodes(biTree root){    //从根节点开始遍历
    if (root == NULL){
        return 0;
    }    
    int count = 0;
    //判断当前节点度数是否为1
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)){
        count = 1;
    }
    //递归左右子树
    return count + countDegreeOneNodes(root->left) + countDegreeOneNodes(root->right);
}

int getTreeHeight (biTree root){
    if (root == NULL){
        return 0;
    }
    int leftHeight = getTreeHeight(root->left); //求左子树高度
    int rightHeight = getTreeHeight(root->right); //求右子树高度
    //返回左右子树高度中的较大值加1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) +1;   
}

pointer findNode (biTree root, int x){
    if (root == NULL){
        return NULL;
    }
    if (root->data == x){
        return root;
    }
    pointer found = findNode(root->left, x); //递归查找左子树
    if(found != NULL){
        return found;
    }
    return findNode(root->right, x);  
}

void freeTree(biTree root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main (){
    //创建一个二叉树
    biTree root = (pointer)malloc(sizeof(TreeNode));
    root->data = 1;

    root->left = (pointer)malloc(sizeof(TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = (pointer)malloc(sizeof(TreeNode));
    root->left->right->data = 4;
    root->left->right->left = NULL; //叶子节点，无子树
    root->left->right->right = NULL;

    root->right = (pointer)malloc(sizeof(TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    // 求度为1的结点数
    printf("Degree 1 nodes: %d\n", countDegreeOneNodes(root));

    // 求树的高度
    printf("Tree height: %d\n", getTreeHeight(root));

    // 查找值为4的结点
    pointer foundNode = findNode(root, 4);
    if (foundNode != NULL) {
        printf("Node with value 4 found at address: %p\n", (void *)foundNode);
    } else {
        printf("Node with value 4 not found.\n");
    }

    freeTree(root);

    return 0;
}