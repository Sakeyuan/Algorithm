#include<iostream>
using namespace std;

//Ŀ�꣺1-i �� from ���õ� to Բ��
void hanoi(int i,string from,string to,string other){
    if(i == 1) cout<<"�� 1 �� "<<from<<" �ƶ��� "<<to<<endl;
    else{
        //�ѵ� i-1 ���̴� from ���õ� other ��
        hanoi(i-1,from,other,to);
        cout<<"�� "<<i<<" �� "<<from<<" �ƶ��� " << to<<endl;
        //�ѵ� i ���̴� from ���õ� to ��
        hanoi(i-1,other,to,from);
    }
}
int main(){
    int n=0;
    cin >> n;
    if(n>0) 
        hanoi(n,"����","����","����");

    system("pause");
    return 0;
}