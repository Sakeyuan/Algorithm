/**
 * @file Prim.cpp
 * @author your name (you@domain.com)
 * @brief 
  ����ķ�㷨������С�������Ĺ��̣�������̰���㷨��˼�롣
  ���ڰ��� N ���������ͨ��������ķ�㷨ÿ�δ���ͨ�����ҳ�һ��Ȩֵ��С�ı�
  �����Ĳ����ظ� N-1 �Σ��� N-1 ��Ȩֵ��С�ı���ɵ�������������С��������
    ��ô������ҳ� N-1 ��Ȩֵ��С�ı��أ�����ķ�㷨��ʵ��˼·�ǣ�
    1.����ͨ���е����ж����Ϊ���ࣨ����Ϊ A ��� B �ࣩ����ʼ״̬�£����ж���λ�� B �ࣻ
    2.ѡ������һ�����㣬����� B ���ƶ��� A �ࣻ
    3.�� B ������ж���������ҳ�һ�������� A ���е�ĳ��������Ȩֵ��С�ıߣ����˱������ŵ� A ���еĶ����ƶ��� B �ࣻ
    4.�ظ�ִ�е� 3  ����ֱ�� B ���е����ж���ȫ���ƶ��� A �࣬ǡ�ÿ����ҵ� N-1 ���ߡ�
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
#define NUM 100
#define INF 0x7fffffff;

void createGraph(int matrix[N][3],int graph[NUM][NUM]){
    for (int i = 0; i < N; i++)
    {
        graph[matrix[i][0]][matrix[i][1]] = matrix[i][2];
        graph[matrix[i][1]][matrix[i][0]] = matrix[i][2];
        
        graph[matrix[i][0]][matrix[i][0]]=0;
        graph[matrix[i][1]][matrix[i][1]]=0;
    }
}

//��ȡB�༯����СȨֵ�±�
int min_dist(int* dist,bool* visited){
    int min=INF;        //��¼��С��Ȩֵ
    int min_index=0;    //��¼��С��Ȩֵ���±�
    for(int i=65;i<NUM;++i){
        if(visited[i]==false && dist[i] < min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

//�����С������
void print_MST(int parent[], int graph[NUM][NUM])
{
    int mingraph = 0;
    printf("��С������Ϊ��\n");
    //���� parent ����
    for (int i = 65; i < NUM; i++) {
        //parent �����±�ֵ��ʾ�������㣬�����±��Ӧ��ֵΪ�ö���ĸ��ڵ�
        printf("%c - %c wight:%d\n", parent[i] , i, graph[i][parent[i]]);//���������±�� 0 ��ʼ��������ʱ���� +1
        //ͳ����С����������Ȩֵ
        mingraph += graph[i][parent[i]];
    }
    printf("��ȨֵΪ��%d", mingraph);
}

void Prim(int graph[NUM][NUM]){
    //dist �������ڼ�¼ B �ඥ�㵽 A �ඥ���Ȩֵ
    //parent �������ڼ�¼��С�������и������㸸�ڵ��λ�ã���������������С������
    //visited �������ڼ�¼������������ A �໹�� B ��
    int dist[NUM];
    int parent[NUM];
    bool visited[NUM];
    //��ʼ��
    for (int i = 65; i < NUM; i++)
    {
        dist[i] =INF;
        parent[i] =-1;
        visited[i] = false;
    }

    // ѡ�� dist �����е�һ�����㣬��ʼѰ����С������
    dist[65] = 0;  // �ö����Ӧ��Ȩֵ��Ϊ 0
    parent[65] = -1; // �ö���û�и��ڵ�

    // ���� P �������ͼ������ѡ�� P-1 ��·�������ɹ�����С������
    for (int i = 0; i < P-1; i++)
    {
        int u=min_dist(dist,visited);  //uΪA�ൽB����С����ָ����Ǹ������±�
        visited[u]=true;

        // �����¶������ A �࣬�����¶��㵽B��ľ��룬�����Ҫ���� dist �����е�����
        for (int j = 65; j < NUM; j++)
        {
            if(graph[u][j]!=0 && visited[j]==false && graph[u][j] < dist[j]){
                dist[j]=graph[u][j];
                parent[j]=u;    // ���� parent �����¼�ĸ������㸸�ڵ����Ϣ
            }
        }
    }
    print_MST(parent,graph);
}  

    
int main(){
    int graph[NUM][NUM];
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
    createGraph(matrix,graph);
    Prim(graph);
    system("pause");
    return 0;
}

