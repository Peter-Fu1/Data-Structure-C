#include <stdio.h>
#include <stdlib.h>

//定义二叉树结点
typedef  char datatype;
typedef struct TreeNode TreeNode;
typedef struct TreeNode {
    datatype data;
    TreeNode *left;
    TreeNode *right;
} *root;

    //寻找指定字符的位置，若存在则返回字符索引，若不存在则返回-1
int findIndex (char arr[], int start, int end, char target) {
    for (int i= start; i<= end; i++){
        if (arr[i]== target) {
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree (char inorder[], char postorder[], int inStart, int inEnd, int* postIndex){
    //
    if (inStart > inEnd) return NULL;

    char rootVal = postorder [*postIndex];  //获取后序遍历的当前根节点
    (*postIndex)--;

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = rootVal;
    root->left = root->right = NULL;
    if (inStart == inEnd) return root;  //如果该节点没有子节点，直接返回
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);  //在中序遍历中找到该根节点的位置，以分出左右子树
    root->right = buildTree(inorder, postorder, inIndex +1, inEnd, postIndex);  //右子树在中序遍历中根节点的右侧
    root->left = buildTree(inorder, postorder, inStart, inIndex -1, postIndex); ////左子树在中序遍历中根节点的左侧
    return root;
}

    //进行中序遍历，检查生成的树是否正确
void inorderTraversal (TreeNode *root){
    if (root== NULL) return;
    inorderTraversal (root->left);
    printf ("%c ", root->data);
    inorderTraversal (root->right);
}

int main (){
    char inorder[] = "GFBEANHM"; //中序遍历序列
    char postorder[] = "GEBFHNMA";  //后序遍历序列

    int postIndex = sizeof(postorder) / sizeof(postorder[0]) - 1;   //获取后序遍历中最后一个节点的索引，即为树的根节点

    TreeNode *root = buildTree (inorder, postorder, 0, sizeof(inorder)/sizeof(inorder[0]) -1, &postIndex);

    // 输出中序遍历结果
    printf("中序遍历结果: ");
    inorderTraversal(root);
    
    return 0;
}