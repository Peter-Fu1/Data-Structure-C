#include <stdio.h>
#define N 6
#define infinite 65536

/*void drawGraph (int G[N][N]){
    printf ("带权有向图的顶点间关系：")
} */

    // (2) 计算顶点入度
void calculateInDegree (int G[N][N], int in_degree[N]) {
    int i=0, j=0;
        //初始化入度数组, 记录每个顶点的入度
    for (i= 0; i< N; i++){
        in_degree[i]= 0;
    }
        //遍历邻接矩阵，计算每个结点的入度(遍历时若值不为 0或∞ ，则该索引行所代表顶点的出度+1，列所代表的结点的入度+！)
    for (i= 0; i< N; i++){
        for (j= 0; j< N; j++){
            if  (G[i][j]!= 0 && G[i][j]!= infinite){
                in_degree [j]++;
            }
        }
    }
        //输出每个顶点的入度
    printf("邻接矩阵的各顶点入度为:\n");
    for (i= 0; i< N; i++){
        printf ("%d\t%d\n", i+1, in_degree[i]);
    }
}

//(3)计算出度为0的顶点数
int countZeroOutDegree (int G[N][N]){

    int i= 0, j= 0;
    int count1;     //count1存储出度为0的顶点数
    for (i= 0; i< N; i++){
        int count2= 0;  //count2储存当前行索引所代表的顶点的出度数
        for (j= 0; j< N; j++){
            if (G[i][j] != 0 && G[i][j]!= infinite){
                count2++;
            }
        }
        //若该顶点出度为0，则出度为0的顶点数+1
        if (count2== 0){
            count1++;
        }
    }
    return count1;
}

int main () {
        //初始化邻接矩阵
    int G[N][N] = {
        {0, 4, 6, infinite, infinite, infinite},
        {infinite, 0, 5, infinite, infinite, infinite},
        {infinite, infinite, 0, 4, 3, infinite},
        {infinite, infinite, infinite, 0, infinite, 3},
        {infinite, infinite, infinite, infinite, 0, 3},
        {infinite, infinite, infinite, infinite, infinite, 0},
    };
    // (2) 计算顶点入度
    int in_degree[N];
    calculateInDegree (G, in_degree);

    
    //(3) 计算出度为0的顶点数
    printf ("出度为0的顶点数为: %d\n", countZeroOutDegree(G));
    return 0;
}
