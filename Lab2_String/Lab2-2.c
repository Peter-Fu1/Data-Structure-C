#include <stdio.h>
#include <stdlib.h>

void generateSpiralMatrix(int n){
    int matrix [10][10];
    int value = 1;
    int top = 0, bottom = n-1;
    int left = 0, right = n-1;

    while (value <= n*n){   //循环输入直到填满数组
        for (int i = left; i <= right && value <= n*n; i++){
            matrix [top][i] = value++;
        }
        top++;  //从左到右输入至当前最右端，上端下移
        for (int i = top; i <= bottom && value <= n*n; i++){
            matrix [i][right] = value++;
        }
        right--;    //从上到下输入至当前最下端，右端左移
        for (int i = right; i >= left && value <= n*n; i--){    //索引i为递减    
            matrix [bottom][i] = value++;
        }
        bottom--;   //从右到左输入到当前最左端，下端上移
        for (int i = bottom; i >= top && value <= n*n; i--){
            matrix [i][left] = value++;
        }
        left++; //从下到上输入到当前最上端，左端右移
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf ("%3d", matrix[i][j]);
        }
        printf ("\n");
    }

}
int main (){
    int i=0, j=0, n=0, var=1;
    printf("请输入方阵的阶数：");
    scanf("%d", &n);
    if (n < 1 || n >= 10) {
        printf("输入的阶数不合法，请输入 1 到 9 之间的整数。\n");
        return 1;
    }
    generateSpiralMatrix(n);
    return 0;
}