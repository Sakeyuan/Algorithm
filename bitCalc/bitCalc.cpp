/**
 * @file bitCalc.cpp
 * @author your name (you@domain.com)
 * @brief ��λ����ʵ�ּӼ��˳�
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
using namespace std;
int add(int a,int b){
    int sum=0;
    while(b != 0){  //ֱ���޽�λ��ֹͣ
        sum=a^b;      //^�൱���޽�λ���
        b=(a & b)<<1; //��λ��Ϣ������н�λ��Ϊ1�������ƶ�һλΪ��λ
        a=sum;
    }
    return sum;
}

int negNum(int n){
    return add(~n,1);
}

int subtract(int a, int b){ //������a+b���෴��b���෴��ȡ����1
    return add(a,negNum(b));
}

int muti(int a, int b){ //�˷����������˷�����
    int sum=0;
    while(b){
        if((b & 1) != 0){
            sum=add(sum,a);
        }
        a<<=1;
        b>>=1;  //��������
    }
    return sum;
}
bool isNeg(int n){
    return n<0;
}

int Div(int a, int b){  //����
    int x=isNeg(a) ? negNum(a) :a;
    int y=isNeg(b) ? negNum(b) :b;
    int sum=0;
    for(int i=31;i>-1;i=subtract(i,1)){
        if((x >> i) >=y){
            sum |=(1<<i);
            x=subtract(x,y<<i);
        }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(sum):sum;
}
int main(){
    int a=-100;
    int b=10;
    cout<<"����:"<<subtract(a,b)<<endl;
    cout<<"�˷�:"<<muti(a,b)<<endl;
    cout<<"����:"<<Div(a,b)<<endl;
    system("pause");

    return 0;
}