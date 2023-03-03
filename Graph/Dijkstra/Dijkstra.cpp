#include<iostream>
using namespace std;
#define INF 0x7fffffff
#define N 6
#include<queue>
typedef struct Node {
    char name;      //�ڵ�����
    int preNode;    //���ڻ���ǰһ����̾���ڵ�
    int Distance;   //����ʼ�ڵ����̾���
    bool visted;    //�ڵ��Ƿ񱻷��ʹ�
};
Node nodes[N];  //�ڵ��
class cmp {
public:
    bool operator()(Node a, Node b) {
        return a.Distance > b.Distance;
    }
};

void init(int start) {
    for (int i = 0; i < N; i++) {
        nodes[i].name = i + 65;
        nodes[i].Distance = INF;
        nodes[i].visted = false;
        nodes[i].preNode =-1;
    }
    nodes[start].Distance = 0;
}
void Dijkstra(int matrix[N][N], int start) {
    init(start);
    priority_queue<Node, vector<Node>, cmp>q;
    q.push(nodes[start]);
    while (!q.empty())
    {
        Node curNode = q.top(); q.pop();
        for (int i = 0; i < N; i++)
        {
            int EdgeLength = matrix[(int)curNode.name - 65][i];
            if (!nodes[i].visted && EdgeLength != 0 && EdgeLength != INF) {
                if (nodes[i].Distance > EdgeLength + nodes[(int)curNode.name - 65].Distance) {
                    nodes[i].Distance = EdgeLength + nodes[(int)curNode.name - 65].Distance;
                    q.push(nodes[i]);
                        nodes[i].preNode = (int)curNode.name - 65;
                }
            }
        }
        nodes[(int)curNode.name - 65].visted = true;
    }
    nodes[start].preNode = start;
}

void printRes(int start) {
    for (int i = 0; i < N; i++)
    {
        cout << "name: " << nodes[i].name << "  distance: " << nodes[i].Distance << "  path:" << (char)(nodes[i].preNode+65);
        cout << endl;
    }

    cout << "��̾���: " << nodes[N - 1].Distance << endl;
    cout << "���·��:";
    Node tmp =nodes[N-1];
    while (tmp.Distance != 0)
    {       
        cout << tmp.name<<" -> ";
        tmp = nodes[tmp.preNode];
    }
    cout << nodes[start].name;
}
int main() {
    int matrix[N][N] = {
        {0,5,1,INF,INF,INF},
        {5,0,2,1,INF,INF},
        {1,2,0,4,8,INF},
        {INF,1,4,0,3,6},
        {INF,INF,8,3,0,INF},
        {INF,INF,INF,6,INF,0} };
    Dijkstra(matrix, 0);
    printRes(0);
    system("pause");
    return 0;
}
