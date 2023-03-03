/**
 * @file isFullBT.cpp
 * @author your name (you@domain.com)
 * @brief 判断是否是满二叉树，nodes==2^h-1 (节点数等于高度的幂次方-1)；
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
using namespace std;
typedef struct node
{
    int val;
    node* left;
    node* right;
};

class Info{ //需要每个节点提供的信息
public:
    int height;
    int nodes;
    Info(int h,int n){
        height = h;
        nodes = n;
    }
};
Info f(node* x){    
    if(x==nullptr) return Info(0,0);
    Info leftDate=f(x->left);
    Info rightDate=f(x->right);
    int heigt=max(leftDate.height,rightDate.height)+1;
    int nodes=leftDate.nodes+rightDate.nodes+1;
    return Info(heigt,nodes);
}

bool isFullBT(node* head){
    if(head==nullptr) return true;
    Info data=f(head);
    return data.nodes == (1<<(data.height-1)); //左移一位表示*2 
}
int main(){
    return 0;
}