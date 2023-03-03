/**
 * @file Prim.cpp
 * @author your name (you@domain.com)
 * @brief 
  普里姆算法查找最小生成树的过程，采用了贪心算法的思想。
  对于包含 N 个顶点的连通网，普里姆算法每次从连通网中找出一个权值最小的边
  这样的操作重复 N-1 次，由 N-1 条权值最小的边组成的生成树就是最小生成树。
    那么，如何找出 N-1 条权值最小的边呢？普里姆算法的实现思路是：
    1.将连通网中的所有顶点分为两类（假设为 A 类和 B 类）。初始状态下，所有顶点位于 B 类；
    2.选择任意一个顶点，将其从 B 类移动到 A 类；
    3.从 B 类的所有顶点出发，找出一条连接着 A 类中的某个顶点且权值最小的边，将此边连接着的 A 类中的顶点移动到 B 类；
    4.重复执行第 3  步，直至 B 类中的所有顶点全部移动到 A 类，恰好可以找到 N-1 条边。
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
using namespace std;
#define N 9
#define P 6
#define INF 0x7fffffff;

void createGraph(int matrix[N][3],int graph[P][P]){
    for (int i = 0; i < N; i++)
    {
        graph[matrix[i][0]-1][matrix[i][1]-1] = matrix[i][2];
        graph[matrix[i][1]-1][matrix[i][0]-1] = matrix[i][2];
        graph[i][i]=0;
    }
}

//获取B类集合最小权值下标
int min_dist(int* dist,bool* visited){
    int min=INF;        //记录最小的权值
    int min_index=0;    //记录最小的权值的下标
    for(int i=0;i<P;++i){
        if(visited[i]==false && dist[i] < min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

//输出最小生成树
void print_MST(int parent[], int graph[P][P])
{
    int mingraph = 0;
    printf("最小生成树为：\n");
    //遍历 parent 数组
    for (int i = 1; i < P; i++) {
        //parent 数组下标值表示各个顶点，各个下标对应的值为该顶点的父节点
        printf("%d - %d wight:%d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);//由于数组下标从 0 开始，因此输出时各自 +1
        //统计最小生成树的总权值
        mingraph += graph[i][parent[i]];
    }
    printf("总权值为：%d", mingraph);
}

void Prim(int graph[P][P]){
    //dist 数组用于记录 B 类顶点到 A 类顶点的权值
    //parent 数组用于记录最小生成树中各个顶点父节点的位置，便于最终生成最小生成树
    //visited 数组用于记录各个顶点属于 A 类还是 B 类
    int dist[P];
    int parent[P];
    bool visited[P];
    //初始化
    for (int i = 0; i < P; i++)
    {
        dist[i] =INF;
        parent[i] =-1;
        visited[i] = false;
    }

    // 选择 dist 数组中第一个顶点，开始寻找最小生成树
    dist[0] = 0;  // 该顶点对应的权值设为 0
    parent[0] = -1; // 该顶点没有父节点

    // 对于 P 个顶点的图，最需选择 P-1 条路径，即可构成最小生成树
    for (int i = 0; i < P-1; i++)
    {
        int u=min_dist(dist,visited);  //u为A类到B类最小距离指向的那个顶点下标
        visited[u]=true;

        // 由于新顶点加入 A 类，更新新顶点到B类的距离，因此需要更新 dist 数组中的数据
        for (int j = 0; j < P; j++)
        {
            if(graph[u][j]!=0 && visited[j]==false && graph[u][j] < dist[j]){
                dist[j]=graph[u][j];
                parent[j]=u;    // 更新 parent 数组记录的各个顶点父节点的信息
            }
        }
    }
    print_MST(parent,graph);
}  

    
int main(){
    int graph[P][P];
    int matrix[N][3]={
                    {1,5,7},
                    {1,3,3},
                    {5,3,8},
                    {1,2,6},
                    {2,3,4},
                    {2,4,2},
                    {3,4,3},
                    {2,6,5},
                    {4,6,2}}; 
    createGraph(matrix,graph);
    Prim(graph);
    system("pause");
    return 0;
}

