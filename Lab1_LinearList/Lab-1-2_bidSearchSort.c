#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  
typedef int datatype;

typedef struct {
    datatype data[MAX_SIZE];  
    int length;          
} Sqlist;

void createSqlist(Sqlist* L) {
    L->length = 0;
    printf("顺序表已创建并初始化。\n");
}

int insert(Sqlist* L, int index, datatype element) {
    if (L->length >= MAX_SIZE) {
        printf("顺序表已满，无法插入元素。\n");
        return 0;
    }
    if (index < 0 || index > L->length) {
        printf("插入位置不合法。\n");
        return 0;
    }

    for (int i = L->length; i > index; i--) {
        L->data[i] = L->data[i - 1];
    }

    L->data[index] = element;
    L->length++;
    return 1;
}

void displaySqlist(Sqlist* L) {
    printf("顺序表元素：");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int bidirectionSort(Sqlist* L) {
    int start = 0;            
    int end = L->length - 1;  
    int exchange = 0;

    while (start <= end) {
        while (L->data[start] <=0) {
            start++; 
        }
        while (L->data[end] >0) {  //条件应为除去0以外的情况，即正数
            end--;   
        }  
            exchange = L->data[start];
            L->data[start] = L->data[end];
            L->data[end] = exchange;
            start++;
            end--;
        }
    } 



int main(){
    Sqlist list;
    createSqlist(&list);
    insert(&list,0,5);
    insert(&list,1,-3);
    insert(&list,2,7);
    insert(&list,3,0);
    insert(&list,3,13);
    insert(&list,3,-5);
    printf("排序前的顺序表元素："); displaySqlist(&list);
    bidirectionSort(&list);
    printf("排序后的顺序表元素："); displaySqlist(&list);
}