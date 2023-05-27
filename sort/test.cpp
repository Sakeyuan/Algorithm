#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
    int val;
    node* next;
    node():val(0),next(NULL){};
    node(int val):val(val),next(NULL){};
};

node* func(node* L1 , node* L2){
    if(L1 == NULL) return L2;
    if(L2 == NULL) return L1;
    node* p1=L1,*p2=L2;
    node* dummy=new node(-1);
    node* prev = dummy;
    while(p1 !=NULL && p2!=nullptr){
        if(p1->val > p2->val){
            prev->next=p2;
            prev = p2;
            p2=p2->next;
        }else{
            prev->next=p1;
            prev = p1;
            p1=p1->next;
        }
    }
    if(p1){
        prev->next=p1;
    }else{
        prev->next=p2;
    }
    return dummy->next;
}

void printList(node* head ){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}

void createNode(node** tail,int val){
    node* tmp=new node(val);
    (*tail)->val=val;
    (*tail)->next = tmp;
    (*tail)=tmp;
    (*tail)->next=nullptr;
}
int main() {
    node* L1 = new node(2);
    node* tail1 = L1;
    node* L2 = new node(1);
    node* tail2 = L2;

    createNode(&tail1,4);
    createNode(&tail1,6);

    // createNode(tail2,1);
    // createNode(tail2,5);
    // createNode(tail2,2);

    printList(L1);
    // printList(L2);
    // node* head=func(L1,L2);
    // printList(head);
    system("pause");
	return 0;
}