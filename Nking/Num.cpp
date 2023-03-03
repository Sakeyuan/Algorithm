/**
 * @file Num.cpp
 * @author your name (you@domain.com)
 * @brief N �ʺ�����
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
using namespace std;

bool ok(int *pos,int i,int j){
    for (int k = 0; k < i; k++)
    {
        if(pos[k]==j || abs(pos[k]-j) == abs(i-k)) return false;
    }
    return true;  
}
int N(int* pos, int i, int n){
    if(i == n) return 1; //�ʺ�ڵ���n�У���ֹ�У����򷵻�һ�ַ���
    int res=0;
    //�ڷŵ�j��
    for(int j=0;j<n;j++){
        if(ok(pos,i,j)){ //ok����Ƿ��ǰ��Ļʺ��ͻ�����ڶԽ��ߺ�ͬһ����
            pos[i]=j;
            res+=N(pos,i+1,n);
        }
    }
    return res;
}
int Num(int n){
    if(n==0) return 0;
    int pos[n]; //pos[i]��ֵ��ʾ�� i �лʺ��λ�ð��ڵڼ���
    int i = 0;
    return N(pos,i,n);
} 

int main(){
    int n=0;
    cout<<"������N: ";
    cin >> n;
    cout<<"һ���� "<< Num(n) <<" �ڷŷ��� "<<endl;;
    system("pause");
    return 0;
}