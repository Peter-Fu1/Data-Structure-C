#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int datatype;

typedef struct {
    datatype data[MAX_SIZE];
    int length;
} Sqlist;

//折半查找插入算法
void binaryInsert(Sqlist *L, datatype k) {
    int low = 0, high = L->length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == k) {
            break; // 插入点已找到
        } else if (L->data[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    //确定插入位置, 确保插入元素位置令表保持有序
    int insertPos = low;
    for (int i = L->length; i > insertPos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[insertPos] = k;
    L->length++;
}

//打印数组
void printList(Sqlist *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main() {
    Sqlist list = {{5, 15, 20, 23, 71, 72, 73, 94}, 8};
    datatype key = 50;

    printf("Original List: \n");
    printList(&list);

    binaryInsert(&list, key);

    printf("List after Inserting %d: \n", key);
    printList(&list);

    return 0;
}