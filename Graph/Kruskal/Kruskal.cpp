/**
 * @file Kruskal.cpp
 * @author your name (you@domain.com)
 * @brief 
    1.将连通网中所有的边按照权值大小做升序排序
    2.从权值最小的边开始选择，只要此边不和已选择的边一起构成环路
    3.就可以选择它组成最小生成树。对于 N 个顶点的连通网
    4.挑选出 N-1 条符合条件的边，这些边组成的生成树就是最小生成树
环路判断：
    1.初始状态下，为连通网中的各个顶点配置不同的标记
    2.对于一个新边，如果它两端顶点的标记不同，就不会构成环路，可以组成最小生成树。
    3.一旦新边被选择，需要将它的两个顶点以及和它直接相连的所有已选边两端的顶点改为相同的标记；
    4.反之，如果新边两端顶点的标记相同，就表示会构成环路。
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<stdlib.h>
using namespace std;
#define N 9
#define P 6
typedef struct Edge{
    int begin;
    int end;
    int weight;
}edge;

void createGraph(edge* graph,int matrix[N][3]){
    for(int i=0;i<N;++i){
        graph[i].begin=matrix[i][0];
        graph[i].end=matrix[i][1];
        graph[i].weight=matrix[i][2];
    }
}
int cmp(const void *a, const void *b){
    //qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序
    return ((edge*)a)->weight-((edge*)b)->weight;
}
void Kruskal(edge* graph,edge* minTree){
    int pVisted[100];    //97代表需要包含进来大写字母的全部asii码
    int num=0; //记录minTree边
    for(int i=65; i<100; i++) pVisted[i]=i;    //初始状态下，每个顶点的标记都不相同
    qsort(graph,N,sizeof(graph[0]),cmp);  //边按照权值大小升序排序
    for (int i = 0; i < N; i++)
    {
        int begin = graph[i].begin;
        int end = graph[i].end;
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路 ******
        if(pVisted[begin] != pVisted[end]){
            minTree[num++]=graph[i];
            int elem=pVisted[begin];
            for (int j = 65; j < 100; j++)
            {               
                if(elem == pVisted[j]){
                    pVisted[j]=pVisted[end];  //将新加入生成树的顶点标记全部改为一样的
                }
            }
            if(num == P-1) break;  //如果选择的边的数量和顶点数相差1，证明最小生成树已经形成，退出循环
        }
    }   
}

void display(edge* minTree) {
    int cost = 0, i;
    printf("最小生成树为:\n");
    for (i = 0; i < P - 1; i++) {
        printf("%c-%c  权值：%d\n", minTree[i].begin, minTree[i].end, minTree[i].weight);
        cost += minTree[i].weight;
    }
    printf("总权值为：%d", cost);
}
int main(){
    edge graph[N]; 
    edge minTree[N];
    int matrix[N][3]={
                    {83,65,7},
                    {83,67,8},
                    {65,67,3},
                    {65,66,6},
                    {67,66,4},
                    {67,68,3},
                    {68,66,2},
                    {68,84,2},
                    {66,84,5}}; 
    createGraph(graph,matrix);
    Kruskal(graph,minTree);
    display(minTree);
    system("pause");
    return 0;
}

