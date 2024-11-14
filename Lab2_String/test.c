#include <stdio.h>
#include <stdlib.h>

void generateSpiralMatrix(int n) {
    int matrix[10][10];  // 假设 n < 10，最大定义为 10x10 的数组
    int value = 1; // 初始填充值
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (value <= n * n) {  // 循环填充直到数组填满
        // 从左到右填充上边界
        for (int i = left; i <= right && value <= n * n; i++) {
            matrix[top][i] = value++;
        }
        top++;  // 上边界下移

        // 从上到下填充右边界
        for (int i = top; i <= bottom && value <= n * n; i++) {
            matrix[i][right] = value++;
        }
        right--;  // 右边界左移

        // 从右到左填充下边界
        for (int i = right; i >= left && value <= n * n; i--) {
            matrix[bottom][i] = value++;
        }
        bottom--;  // 下边界上移

        // 从下到上填充左边界
        for (int i = bottom; i >= top && value <= n * n; i--) {
            matrix[i][left] = value++;
        }
        left++;  // 左边界右移
    }

    // 输出生成的螺旋方阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);  // 使输出对齐
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("请输入方阵的阶数：");
    scanf("%d", &n);

    if (n < 1 || n >= 10) {
        printf("输入的阶数不合法，请输入 1 到 9 之间的整数。\n");
        return 1;
    }

    generateSpiralMatrix(n);  // 调用生成螺旋矩阵的函数
    return 0;
}
