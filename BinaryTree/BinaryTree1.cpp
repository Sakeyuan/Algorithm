//递归二叉树
#include<iostream>
static int i=-1;
typedef struct Node
{
    char data;
    struct Node *lChild;
    struct Node *rChild;
}*tree,treeNode;
void createBinaryTree(tree &root,char *a){
    ++i;
    if(a[i]=='#'){
        root=NULL;
        return;
    }        
    else{
        root=new treeNode;
        root->data=a[i];
        std::cout<<root->data<<" ";
        createBinaryTree(root->lChild,a);
        std::cout<<root->data<<" ";
        createBinaryTree(root->rChild,a);
        std::cout<<root->data<<" ";       
    }
}
//先序遍历
void DLR(tree &root){
    if(root==NULL) return;
    //递归序中第一次出现的位置
    std::cout<<root->data<<" ";

    DLR(root->lChild);
    //递归序中第二次出现的位置，回溯

    DLR(root->rChild);
    //递归序中第三次出现的位置，回溯
}

//中序遍历
void LDR(tree &root){
    if(root==NULL) return;
    //递归序中第一次出现的位置

    LDR(root->lChild);
    //递归序中第二次出现的位置，回溯

    std::cout<<root->data<<" ";
    LDR(root->rChild);

    //递归序中第三次出现的位置，回溯
}

//后序遍历
void LRD(tree &root){ 
    if(root==NULL) return;
    //递归序中第一次出现的位置  

    LRD(root->lChild);
    //递归序中第二次出现的位置，回溯

    LRD(root->rChild);
    //递归序中第三次出现的位置，回溯
    std::cout<<root->data<<" ";
}
int main(){
    char a[]={'A','B','C','#','#','#','D','#','E','#','#'};//递归序A B C C C B B A D D E E E D A
    tree root=nullptr;
    createBinaryTree(root,a);
    std::cout<<std::endl<<"先序遍历:";
    DLR(root);
    std::cout<<std::endl<<"中序遍历:";
    LDR(root);
    std::cout<<std::endl<<"后序遍历:";
    LRD(root);
    std::cout<<std::endl;
    system("pause");
    return 0;
}