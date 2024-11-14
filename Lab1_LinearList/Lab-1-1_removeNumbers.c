#include <stdio.h>
#define MAX_SIZE 100

typedef char datatype;
#define DATATYPE_FORMAT "%c"    //预定义格式输出符，方便替换变量类型

typedef struct {
    datatype data[MAX_SIZE];
    int length;
} Sqlist;

void createSqlist(Sqlist* L);
int insert(Sqlist* L, int index, datatype element);
void displaySqlist(Sqlist* L);
void removeZeroElements (Sqlist *L);
void removeNumbers (Sqlist *L);

int main () {
    Sqlist list;
    createSqlist(&list);

    insert(&list, 0, '1');
    insert(&list, 1, 'A');
    insert(&list, 2, '2');
    insert(&list, 3, 'B');
    insert(&list, 4, '#');

    printf("删除数字字符前的顺序表元素："); displaySqlist(&list);
    removeNumbers(&list);
    printf("删除数字字符后的顺序表元素："); displaySqlist(&list);
}

void createSqlist(Sqlist* L) {
    // 初始化线性表的长度
    L->length = 0;
    printf("顺序表已创建并初始化。\n");
}

// 向顺序表中插入元素
int insert(Sqlist* L, int index, datatype element) {
    if (L->length >= MAX_SIZE) {
        printf("顺序表已满，无法插入元素。\n");
        return 0;
    }
    if (index < 0 || index > L->length) {
        printf("插入位置不合法。\n");
        return 0;
    }
    if (!((element >= 65 && element <= 90) ||  // 大写字母 A-Z
          (element >= 97 && element <= 122) || // 小写字母 a-z
          (element >= 48 && element <= 57))) { // 数字字符 0-9
        printf("非法字符，插入失败。只能插入英文字符或数字字符。\n");
        return 0;
    }

    // 从插入位置后移元素
    for (int i = L->length; i > index; i--) {
        L->data[i] = L->data[i - 1];
    }

    // 插入元素
    L->data[index] = element;
    L->length++;
    return 1;
}

// 输出顺序表的所有元素
void displaySqlist(Sqlist* L) {
    for (int i = 0; i < L->length; i++) {
        printf(""DATATYPE_FORMAT" ", L->data[i]);
    }
    printf("\n");
}

void removeNumbers (Sqlist *L){
    int i, s;
    s = 0;
    for (i=0;i<L->length;i++){
        if (L->data[i]>=48 & L->data[i]<=57){
            s++;
        }
        else {
            L->data[i-s]= L->data[i];
        }
    }
    L->length = L->length - s ;
}