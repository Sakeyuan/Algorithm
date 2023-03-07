/**
 * @file getMax.cpp
 * @author your name (you@domain.com)
 * @brief ��ʹ�ñȽϵķ������ó����һ��
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
using namespace std;

//��ͬ����0����ͬΪ1
bool flip(int n){
    return n^1;
}

//�ж�n����λ��0Ϊ������1Ϊ����
bool sign(int n){
    return flip((n >> 31) & 1);
}

int getMax(const int a,const int b){
    int c=a-b;
    bool sa=sign(a);
    bool sb=sign(b);
    bool sc=sign(c);
    bool diff_ab=sa^sb;         //a��b���Ų�һ��
    bool same_ab=flip(diff_ab); //a��bһ��
    bool return_a=diff_ab*sa + same_ab*sc; //1)a��b���Ų�һ����aҪ����0���ŷ���a   2��a��b����һ����a-b����0
    bool return_b=flip(return_a);
    return a*return_a+b*return_b;   //+������ѡ��һ
}

int main(){
    int a=100;
    int b=10;
    cout<<getMax(a,b);
    system("pause");
    return 0;
}