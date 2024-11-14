#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node* pointer;
typedef pointer lklist;

struct node {
    datatype data;
    pointer next;
};

pointer createNode(datatype data){  //创建新结点
    pointer newNode = (pointer)malloc(sizeof(pointer));
    newNode->data= data;
    newNode->next= NULL;
    return newNode;
}

void combinedLinkedList (lklist *ha, lklist hb){
    pointer A,B,prevA;
    A= *ha; B= hb;
    prevA= NULL;

    while (B!=NULL){
        while (A!= NULL && A->data < B->data){  //寻找合适的插入位置
            prevA = A;
            A = A->next;
        }
        if (prevA != NULL && prevA->data == B->data){   //检查A，B值是否相等，相等则跳过B
            B = B-> next;
        }
        else {
            pointer C = createNode (B->data);
            C->next = A;    //此时B的值小于A的值，在A结点前插入
            if(prevA== NULL){
                *ha = C;    //若先前结点为空，则更新链表头
            }
            else {
                prevA->next = C;    //若先前结点不为空，则插入到先前结点后（更新先前结点next域）
            }
            prevA= C;   //将A的先前结点更新为插入的结点C
            B= B->next;     // 插入完成
        }
    }
}

void printList(lklist head) {
    pointer current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {        
    lklist ha = createNode(1);  //创建链表A和B
    ha->next = createNode(3);
    ha->next->next = createNode(5);

    printf("合并前的链表A：");
    printList(ha);

    lklist hb = createNode(2);
    hb->next = createNode(3);
    hb->next->next = createNode(4);
    printf("合并前的链表B：");
    printList(hb);

    combinedLinkedList(&ha, hb);
    printf("合并后的链表A：");    
    printList(ha);

    return 0;
}