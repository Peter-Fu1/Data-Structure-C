#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int datatype;

typedef struct {
    datatype data[MAX_SIZE];
    int length;
} Sqlist;

void swap (Sqlist *L, int i, int j);
void printList(Sqlist *L);

void bubbleSort (Sqlist *L) {
    int flag= 1;
    for (int i= 0; i< L->length && flag; i++){
        flag= 0;
        for (int j= L->length- 1; j>= i; j--){
            if (L->data[j+1]< L->data[j]){
                swap (L, j, j+1);
                flag= 1;
            }
        }
    }
}

void selectionSort (Sqlist *L){
    int i, j, min;
    for (i= 0; i< L->length- 1; i++){
        min = i;
        for(j= i+1; j< L->length; j++){ //从第二位开始检索序列中的最小值
            if (L->data[j]< L->data[min]){
                min= j;
            }
        }
        if(min!= i){    //若检索完成后最小值不在当前位置，则将最小值交换至当前位置
            swap (L, i, min);
        }
    }
}

void quickSort (Sqlist *L, int low, int high) {
    if (low < high) {
        datatype pivot = partition (L, low, high);
        quickSort(L, low, pivot- 1);
        quickSort(L, pivot+ 1, high);
    }
}

int main (){
    Sqlist list1 = {{72, 73, 71, 23, 94, 15, 5, 20}, 8};
    Sqlist list2 = {{72, 73, 71, 23, 94, 15, 5, 20}, 8};
    Sqlist list3 = {{72, 73, 71, 23, 94, 15, 5, 20}, 8};

    printf("Original List: \n");
    printList(&list1);

    // 直接选择排序
    selectionSort(&list1);
    printf("List after Selection Sort: \n");
    printList(&list1);

    // 冒泡排序
    bubbleSort(&list2);
    printf("List after Bubble Sort: \n");
    printList(&list2);

    // 快速排序
    quickSort(&list3, 0, list3.length - 1);
    printf("List after Quick Sort: \n");
    printList(&list3);

    return 0;
}

void swap (Sqlist *L, int i, int j) {
    datatype temp = L->data[i];
    L->data[i]= L->data[j];
    L->data[j]= temp;
}

int partition(Sqlist *L, int low, int high) {
    datatype pivot = L->data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (L->data[j] < pivot) {
            i++;
            swap(L, i, j);
        }
    }
    swap(L, i + 1, high);
    return i + 1;
}

void printList(Sqlist *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}