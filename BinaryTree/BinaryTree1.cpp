//�ݹ������
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
//�������
void DLR(tree &root){
    if(root==NULL) return;
    //�ݹ����е�һ�γ��ֵ�λ��
    std::cout<<root->data<<" ";

    DLR(root->lChild);
    //�ݹ����еڶ��γ��ֵ�λ�ã�����

    DLR(root->rChild);
    //�ݹ����е����γ��ֵ�λ�ã�����
}

//�������
void LDR(tree &root){
    if(root==NULL) return;
    //�ݹ����е�һ�γ��ֵ�λ��

    LDR(root->lChild);
    //�ݹ����еڶ��γ��ֵ�λ�ã�����

    std::cout<<root->data<<" ";
    LDR(root->rChild);

    //�ݹ����е����γ��ֵ�λ�ã�����
}

//�������
void LRD(tree &root){ 
    if(root==NULL) return;
    //�ݹ����е�һ�γ��ֵ�λ��  

    LRD(root->lChild);
    //�ݹ����еڶ��γ��ֵ�λ�ã�����

    LRD(root->rChild);
    //�ݹ����е����γ��ֵ�λ�ã�����
    std::cout<<root->data<<" ";
}
int main(){
    char a[]={'A','B','C','#','#','#','D','#','E','#','#'};//�ݹ���A B C C C B B A D D E E E D A
    tree root=nullptr;
    createBinaryTree(root,a);
    std::cout<<std::endl<<"�������:";
    DLR(root);
    std::cout<<std::endl<<"�������:";
    LDR(root);
    std::cout<<std::endl<<"�������:";
    LRD(root);
    std::cout<<std::endl;
    system("pause");
    return 0;
}