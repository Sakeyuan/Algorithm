/**
 * @file Kruskal.cpp
 * @author your name (you@domain.com)
 * @brief 
    1.����ͨ�������еı߰���Ȩֵ��С����������
    2.��Ȩֵ��С�ı߿�ʼѡ��ֻҪ�˱߲�����ѡ��ı�һ�𹹳ɻ�·
    3.�Ϳ���ѡ���������С������������ N ���������ͨ��
    4.��ѡ�� N-1 �����������ıߣ���Щ����ɵ�������������С������
��·�жϣ�
    1.��ʼ״̬�£�Ϊ��ͨ���еĸ����������ò�ͬ�ı��
    2.����һ���±ߣ���������˶���ı�ǲ�ͬ���Ͳ��ṹ�ɻ�·�����������С��������
    3.һ���±߱�ѡ����Ҫ���������������Լ�����ֱ��������������ѡ�����˵Ķ����Ϊ��ͬ�ı�ǣ�
    4.��֮������±����˶���ı����ͬ���ͱ�ʾ�ṹ�ɻ�·��
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
    //qsort��������ʹ�ã�ʹedges�ṹ���еı߰���Ȩֵ��С��������
    return ((edge*)a)->weight-((edge*)b)->weight;
}
void Kruskal(edge* graph,edge* minTree){
    int pVisted[100];    //97������Ҫ����������д��ĸ��ȫ��asii��
    int num=0; //��¼minTree��
    for(int i=65; i<100; i++) pVisted[i]=i;    //��ʼ״̬�£�ÿ������ı�Ƕ�����ͬ
    qsort(graph,N,sizeof(graph[0]),cmp);  //�߰���Ȩֵ��С��������
    for (int i = 0; i < N; i++)
    {
        int begin = graph[i].begin;
        int end = graph[i].end;
        //�������λ�ô����Ҷ���ı�ǲ�ͬ��˵������һ�������У����������· ******
        if(pVisted[begin] != pVisted[end]){
            minTree[num++]=graph[i];
            int elem=pVisted[begin];
            for (int j = 65; j < 100; j++)
            {               
                if(elem == pVisted[j]){
                    pVisted[j]=pVisted[end];  //���¼����������Ķ�����ȫ����Ϊһ����
                }
            }
            if(num == P-1) break;  //���ѡ��ıߵ������Ͷ��������1��֤����С�������Ѿ��γɣ��˳�ѭ��
        }
    }   
}

void display(edge* minTree) {
    int cost = 0, i;
    printf("��С������Ϊ:\n");
    for (i = 0; i < P - 1; i++) {
        printf("%c-%c  Ȩֵ��%d\n", minTree[i].begin, minTree[i].end, minTree[i].weight);
        cost += minTree[i].weight;
    }
    printf("��ȨֵΪ��%d", cost);
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

