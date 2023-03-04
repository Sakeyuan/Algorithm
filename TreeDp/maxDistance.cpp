#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief 
 * 
 * ����dp��·��һ��:
    ��ĳ���ڵ�XΪͷ�ڵ�������У�����������Щ������,�������ַ�������X������
    ����X����������X�������ĽǶ������ǿ����Ե�
����dp��·�ڶ���:
    ���ݵ�һ���Ŀ����Է����� �г�������Ҫ����Ϣ
����dp��·������:
    �ϲ��ڶ�������Ϣ�����������������ͬ����Ҫ�󣬲�д����Ϣ�ṹ
����dp��·���Ĳ�:
    ��Ƶݹ麯�����ݹ麯���Ǵ�����XΪͷ�ڵ������µĴ𰸡�
    ������Ƶݹ��basecase,Ĭ��ֱ�ӵõ�������������������Ϣ���Լ��ѿ���������
    �ϣ�����Ҫ���ص���������Ϣ�ṹ���ĸ�С����
    
 * @return int 
 */
struct Node{
    int val;
    Node* left;
    Node* right;
};

class Info{ //��ڵ�Ѱ�����Ϣ
public:
    int height;
    int maxDistance;
    Info(int h,int dis){
        this->height = h;
        this->maxDistance = dis;
    }
};

Info process(Node *head){
    if(head == NULL){ //base case
        return Info(0,0);
    }
    Info left =process(head->left);
    Info right =process(head->right);
    int p1=left.maxDistance;
    int p2=right.maxDistance;
    int p3=left.height+1+right.height;
    int maxDistance = max(p3,max(p2,p1));
    int height=max(left.height,right.height)+1;
    return Info(maxDistance,height);
} 
//��������dp�����������������
int maxDistance(Node* head){
    return process(head).maxDistance;
}

int main(){
    Node* head = new Node;
    maxDistance(head);
    return 0;
}