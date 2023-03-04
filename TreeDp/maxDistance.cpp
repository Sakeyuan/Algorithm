#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief 
 * 
 * 树形dp套路第一步:
    以某个节点X为头节点的子树中，分析答案有哪些可能性,并且这种分析是以X的左子
    树、X的右子树和X整棵树的角度来考虑可能性的
树形dp套路第二步:
    根据第一步的可能性分析， 列出所有需要的信息
树形dp套路第三步:
    合并第二步的信息，对左树和右树提出同样的要求，并写出信息结构
树形dp套路第四步:
    设计递归函数，递归函数是处理以X为头节点的情况下的答案。
    包括设计递归的basecase,默认直接得到左树和右树的所有信息，以及把可能性做整
    合，并且要返回第三步的信息结构这四个小步骤
    
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
//利用树形dp方法求解树的最大距离
int maxDistance(Node* head){
    return process(head).maxDistance;
}

int main(){
    Node* head = new Node;
    maxDistance(head);
    return 0;
}