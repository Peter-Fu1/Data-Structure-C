#include <Stdio.h>
#define MAX_SIZE 100

typedef struct {
    int row;
    int column;
    int value;
}   Triple;

typedef struct {
    Triple data [MAX_SIZE]; //三元组数组
    int rows;   //稀疏矩阵行数
    int columns;    //稀疏矩阵列数
    int num;    //非零元个数
}   SparseMatrix;

void createSparseMatrix (SparseMatrix *matrix, int rows, int columns, int num, int elements[][3]){  
    //参数：稀疏矩阵变量、稀疏矩阵的行数、列数、非零元个数以及非零元素数组
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->num = num;
    for (int i = 0; i < num; i++){
        matrix->data[i].row = elements[i][0];   //数据元素在稀疏矩阵中的行
        matrix->data[i].column = elements[i][1];    //数据元素在稀疏矩阵中的列
        matrix->data[i].value = elements[i][2];     //数据元素的值
    }
}

void printSparseMatrix(SparseMatrix matrix){
    printf("行  列  值\n");
    for (int i = 0; i < matrix.num; i++) {
        printf("%2d  %2d  %2d\n", matrix.data[i].row, matrix.data[i].column, matrix.data[i].value);
    }
    printf("\n");  
}

SparseMatrix addSparseMatrix(SparseMatrix a, SparseMatrix b){
    //变量初始化
    SparseMatrix result;
    result.rows = a.rows;
    result.columns = a.columns;
    result.num = 0;
    int i = 0, j = 0;

    while (i < a.num && j < b.num){
        //若遍历到的a矩阵的非零元素所在的位置比b矩阵的小，则将该a矩阵非零元素赋给结果矩阵
        if (a.data[i].row < b.data[j].row || (a.data[i].row == b.data[j].row && a.data[i].column < b.data[j].column)){
            result.data[result.num++] = a.data[i++];
        }
        //若遍历到的b矩阵的非零元素所在的位置比a矩阵的小，则将该b矩阵非零元素赋给结果矩阵
        else if (b.data[j].row < a.data[i].row || (b.data[j].row == a.data[i].row && b.data[j].column < a.data[i].column)){
            result.data[result.num++] = b.data[j++];
        }
        //若遍历到的a,b矩阵的非零元处在矩阵中的同一位置上，则将该元素所处的行、列值和两个非零元素的值相加的结果添加到结果矩阵
        else {
            result.data[result.num] = a.data[i];
            result.data[result.num++].value = a.data[i++].value + b.data[j++].value;
        }
    }
    //若a，b矩阵有其中一个先遍历完了非零元，则将另一个矩阵剩余的非零元素添加到结果矩阵
    while (i < a.num) result.data[result.num++] = a.data[i++];
    while (j < b.num) result.data[result.num++] = b.data[j++];
    //返回结果矩阵
    return result;
}

int main (){
    SparseMatrix a,b,sum;
    int elementsA[][3] = { {0,0,1}, {0,2,3}, {1,1,1}, {2,2,1}, {3,2,1},{3,3,1}};
    createSparseMatrix (&a,4,4,6,elementsA);
    printf("三元组a\n");
    printSparseMatrix (a);
    int elementsB[][3] = {{0,0,3}, {1,1,4}, {2,2,1},{3,3,2}};
    createSparseMatrix (&b,4,4,4,elementsB);
    printf("三元组b\n");
    printSparseMatrix (b);
    printf("三元组a+b\n");
    printSparseMatrix(addSparseMatrix(a,b));
}