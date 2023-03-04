#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief 利用树形dp方法求解树的最大距离
 * 
 * @return int 
 */
struct Node{
    int val;
    Node* left;
    Node* right;
};

class Info{ //向节点寻求的信息
public:
    int height;
    int maxDistance;
    Info(int h,int dis){
        this->height = h;
        this->maxDistance = dis;
    }
};

Info process(Node *head){
    if(head == NULL){
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
int maxDistance(Node* head){
    return process(head).maxDistance;
}

int main(){
    Node* head = new Node;
    maxDistance(head);
    return 0;
}