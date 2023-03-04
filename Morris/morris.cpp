#include<iostream>
#include<sstream>
using namespace std;

/**
 * @brief //二叉树O(n)遍历
 * Morris遍历细节 时间复杂度o(n)，空间复杂度o（1）
    假设来到当前节点cur,开始时cur来到头节点位置
    1)如果cur没有左孩子，cur向右移动(cur = cur.right)
    
    2)如果cur有左孩子，找到左子树.上最右的节点mostRight:
        a.如果mostRight的右指针指向空，让其指向cur,然后cur向左移动(cur = cur.eft)
        b.如果mostRight的右指针指向cur,让其指向null,
    然后cur向右移动(cur = cur.right)
    
    3) cur为空时遍历停止
 */
typedef struct Node {
    int val;
    Node* left;
    Node* right;
    Node() :val(0), left(nullptr), right(nullptr) {}
    Node(int v) :val(v), left(nullptr), right(nullptr) {
    }
}Node;

Node* createBT(istringstream& ss) {
    string tmp;
    ss >> tmp;
    if (tmp == "#") return nullptr;
    Node* node = new Node(stoi(tmp)); //stoi将tmp转为int
    node->left = createBT(ss);
    node->right = createBT(ss);
    return node;
}

void Morris(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur->right != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //移动到左子树的最右节点，且需要第一次来到
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //第一次来到cur
                mostRight->right=cur;
                cur=cur->left;
                continue;
            }else{
                mostRight->right=NULL;
            }
        }   
        cur=cur->right;
    }
}

//前序遍历
void MorrisPre(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //移动到左子树的最右节点，且需要第一次来到
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //第一次来到cur
                cout<<cur->val<<" ";
                mostRight->right=cur;
                cur=cur->left;
                continue;
            }else{
                mostRight->right=NULL;
            }
        }
        else{
            cout<<cur->val<<" ";
        }   
        cur=cur->right;
    }
}

//中序遍历
void MorrisMid(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //移动到左子树的最右节点，且需要第一次来到
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //第一次来到cur
                mostRight->right=cur;
                cur=cur->left;
                continue;
            }else{
                mostRight->right=NULL;
            }
        }
        cout<<cur->val<<" ";  //第二次和没有左节点都打印   
        cur=cur->right;
    }
}

//翻转链表
Node* reverse(Node* head){
    Node* cur=head;
    Node* pre=NULL;
    while(cur){
        Node* next=cur->right;
        cur->right=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}
void invertedPrint(Node* head){
    Node* tail=reverse(head);
    Node* cur=tail;
    while(cur){
        cout<<cur->val<<" ";
        cur=cur->right;
    }
    reverse(tail);
}

//后序遍历
void MorrisLast(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //移动到左子树的最右节点，且需要第一次来到
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //第一次来到cur
                mostRight->right=cur;
                cur=cur->left;
                continue;
            }else{
                mostRight->right=NULL;
                invertedPrint(cur->left);//第二次来到cur，逆序打印左树的右边界
            }
        }  
        cur=cur->right;
    }
    invertedPrint(head);//打印整棵树右边界
}


int main() {
    Node* head = nullptr;
    string str = "5 1 # # 4 3 # # 6 # #";
    istringstream ss(str);
    head = createBT(ss);
    cout<<"前序遍历:" <<endl;
    MorrisPre(head);
    cout<<"\n中序遍历:" <<endl;
    MorrisMid(head);
    cout<<"\n后序遍历:" <<endl;
    MorrisLast(head);
    cout << endl;
    system("pause");
    return 0;
}