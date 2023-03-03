#include<iostream>
using namespace std;
#include<string>
static int i=-1;
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}*tree,treeNode;
string serialize(tree& root);
void createBinaryTree(tree &root,int *a){
    ++i;
    if(a[i]==0){
        root=NULL;
        return;
    }        
    else{
        root=new treeNode;
        root->data=a[i];
        std::cout<<root->data<<" ";
        createBinaryTree(root->left,a);
        std::cout<<root->data<<" ";
        createBinaryTree(root->right,a);
        std::cout<<root->data<<" ";       
    }
}

string code="";
void encoded(tree& root){
    if(root==NULL) {
        code+=(char)root->data;
        return;
    };

    serialize(root->left);
    serialize(root->right); 

}
string serialize(tree& root) {
    if(root==NULL) return;
    encoded(root);
    return code;
}

// Decodes your encoded data to tree.
treeNode* deserialize(string data) {
    
}

int main(){
    tree root;
    int a[]={1,2,0,0,3,4,0,0,5,0,0};
    createBinaryTree(root,a);
    serialize(root);
    return 0;
}