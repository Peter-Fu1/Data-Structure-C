#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node* pointer;
typedef pointer lklist;

struct node {
    datatype data;
    pointer next;
};

pointer createNode(datatype data) {
    pointer newNode = (pointer)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void combinedLinkedList(lklist *ha, lklist hb) {
    pointer A = *ha; // A 的起始节点
    pointer B = hb; // B 的起始节点
    pointer prevA = NULL; // 用于追踪 A 的前一个节点

    while (B != NULL) {
        // 找到合适的插入位置
        while (A != NULL && A->data < B->data) {
            prevA = A; // 更新 prevA
            A = A->next; // 移动到下一个节点
        }

        // 检查是否相等
        if (A != NULL && A->data == B->data) {
            B = B->next; // 相等则跳过 B
        } else {
            // 插入 B 到 A 之前
            pointer newNode = createNode(B->data);
            newNode->next = A; // 指向 A
            if (prevA == NULL) {
                *ha = newNode; // 如果是插入到头部，更新 ha
            } else {
                prevA->next = newNode; // 更新 prevA 的 next 指向 newNode
            }
            prevA = newNode; // 更新 prevA 为新插入的节点
            B = B->next; // 移动到 hb 的下一个节点
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
    // 创建链表 A 和 B
    lklist ha = createNode(1); // 示例数据
    ha->next = createNode(3);
    ha->next->next = createNode(5);

    lklist hb = createNode(2);
    hb->next = createNode(3);
    hb->next->next = createNode(4);

    // 进行归并
    combinedLinkedList(&ha, hb);

    // 打印结果
    printList(ha);

    return 0;
}
