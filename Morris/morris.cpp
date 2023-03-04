#include<iostream>
#include<sstream>
using namespace std;

/**
 * @brief //������O(n)����
 * Morris����ϸ�� ʱ�临�Ӷ�o(n)���ռ临�Ӷ�o��1��
    ����������ǰ�ڵ�cur,��ʼʱcur����ͷ�ڵ�λ��
    1)���curû�����ӣ�cur�����ƶ�(cur = cur.right)
    
    2)���cur�����ӣ��ҵ�������.�����ҵĽڵ�mostRight:
        a.���mostRight����ָ��ָ��գ�����ָ��cur,Ȼ��cur�����ƶ�(cur = cur.eft)
        b.���mostRight����ָ��ָ��cur,����ָ��null,
    Ȼ��cur�����ƶ�(cur = cur.right)
    
    3) curΪ��ʱ����ֹͣ
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
    Node* node = new Node(stoi(tmp)); //stoi��tmpתΪint
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
            while (mostRight->right != NULL && mostRight->right != cur) //�ƶ��������������ҽڵ㣬����Ҫ��һ������
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //��һ������cur
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

//ǰ�����
void MorrisPre(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //�ƶ��������������ҽڵ㣬����Ҫ��һ������
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //��һ������cur
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

//�������
void MorrisMid(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //�ƶ��������������ҽڵ㣬����Ҫ��һ������
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //��һ������cur
                mostRight->right=cur;
                cur=cur->left;
                continue;
            }else{
                mostRight->right=NULL;
            }
        }
        cout<<cur->val<<" ";  //�ڶ��κ�û����ڵ㶼��ӡ   
        cur=cur->right;
    }
}

//��ת����
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

//�������
void MorrisLast(Node* head){
    if(head == NULL) return;
    Node* cur=head;
    Node* mostRight=NULL;
    while (cur != NULL)
    {   
        mostRight=cur->left;
        if(mostRight != NULL){
            while (mostRight->right != NULL && mostRight->right != cur) //�ƶ��������������ҽڵ㣬����Ҫ��һ������
                mostRight=mostRight->right;

            if(mostRight->right == NULL){ //��һ������cur
                mostRight->right=cur;
                cur=cur->left;
                continue;
            }else{
                mostRight->right=NULL;
                invertedPrint(cur->left);//�ڶ�������cur�������ӡ�������ұ߽�
            }
        }  
        cur=cur->right;
    }
    invertedPrint(head);//��ӡ�������ұ߽�
}


int main() {
    Node* head = nullptr;
    string str = "5 1 # # 4 3 # # 6 # #";
    istringstream ss(str);
    head = createBT(ss);
    cout<<"ǰ�����:" <<endl;
    MorrisPre(head);
    cout<<"\n�������:" <<endl;
    MorrisMid(head);
    cout<<"\n�������:" <<endl;
    MorrisLast(head);
    cout << endl;
    system("pause");
    return 0;
}