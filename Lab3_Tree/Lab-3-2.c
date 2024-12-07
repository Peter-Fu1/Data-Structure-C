#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//定义二叉树结点
typedef struct TreeNode TreeNode;
typedef struct TreeNode {
    char data;
    TreeNode *left;
    TreeNode *right;
} *root;

//定义队列节点
typedef struct QueueNode {
    TreeNode *node;
    int i;
    struct QueueNode *next;
} QueueNode;

//定义队列
typedef struct Queue {
    QueueNode *front;   //队头
    QueueNode *rear;    //队尾
} Queue;

//队列和二叉树相关操作函数定义
void initQueue (Queue *q);
int isQueueEmpty (Queue *q);
void enqueue (Queue *q, TreeNode *node, int i);
void dequeue (Queue *q, TreeNode **node, int *i);
int getTreeHeight (TreeNode *root);
void printArray (char *A, int max_size);

//将二叉链表转化为顺序存储，将二叉树根节点地址、存放二叉链表元素的字符数组的地址、以及二叉树的节点数作为形参
void convertToSequential (TreeNode *b, char *A, int max_size) {
    if (b == NULL) return;
    Queue q;
    initQueue (&q);  //初始化队列
    enqueue (&q, b, 0); //对根节点进行入队操作

    //初始化数组
    for (int i= 0; i< max_size; i++){
        A[i]= '#';  //当二叉树节点为空时，顺序存储中的元素为'#'
    }

    //层次遍历, 从已在队列中的根节点开始，直到所有节点都经历了入队出队，遍历完成
    while (!isQueueEmpty(&q)){
        TreeNode *node;
        int index;
        dequeue (&q, &node, &index);

        //将当前节点的值放入顺序存储中
        if (node!= NULL && index< max_size){
            A[index] = node->data;

            //左孩子入队
            if (node->left!= NULL){
                enqueue (&q, node->left, 2*index+1);
            }

            //右孩子入队
            if (node->right!= NULL){
                enqueue (&q, node->right, 2*index+2);
            }
        }
    }
}

int main (){
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));  //创建根节点并分配内存
    root->data = 'A';
    root->left = (TreeNode *)malloc(sizeof(TreeNode));  //创建左孩子节点并分配内存
    root->left->data = 'B';
    root->right = (TreeNode *)malloc(sizeof(TreeNode)); //创建右孩子节点并分配内存
    root->right->data = 'C';
    //以此类推
    root->left->left = (TreeNode *)malloc(sizeof(TreeNode));    
    root->left->left->data = 'D';
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->data = 'E';

    //注意树叶节点的左右子树要设置为空节点
    root->left->left->left=NULL;
    root->left->left->right=NULL;
    root->right->right->left=NULL;
    root->right->right->right=NULL;


    // 计算二叉树高度和数组大小
    int height = getTreeHeight(root);
    int max_size = (int)pow(2, height) - 1;

    //创建用于存放转化后的二叉树的顺序存储数组
    char *A = (char *)malloc(max_size * sizeof(char));
    convertToSequential(root, A, max_size);

    // 打印结果
    printf("转化后的顺序存储数组为:\n");
    printArray(A, max_size);

}

void initQueue (Queue *q){
    q->front = q->rear = NULL;
}

int isQueueEmpty (Queue *q){
    return q->front == NULL;
}

//入队
void enqueue (Queue *q, TreeNode *node, int i){
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->i = i;
    newNode->next = NULL;
    if (isQueueEmpty(q)) q->front = q->rear = newNode;  //若队列为空
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//出队，并利用指针记录出队节点信息
void dequeue (Queue *q, TreeNode **node, int *i){
    if (isQueueEmpty(q)){
        *node = NULL;
        *i = -1;
        return;
    }
    QueueNode *temp = q->front;
    *node = temp->node;
    *i = temp->i;
    q->front = temp->next;
    if (isQueueEmpty(q)){
        q->rear = NULL;
    }
    free(temp);
}

int getTreeHeight (TreeNode *root){
    if (root== NULL)    return 0;
    int left_height = getTreeHeight(root->left);
    int right_height = getTreeHeight(root->right);
    return (left_height > right_height ? left_height : right_height) +1;
}

//打印转化为顺序存储后的数组
void printArray (char *A, int max_size) {
    for (int i= 0; i< max_size; i++){
        printf ("%c", A[i]);
    }
    printf ("\n");
}