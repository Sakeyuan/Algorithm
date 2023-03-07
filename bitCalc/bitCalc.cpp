/**
 * @file bitCalc.cpp
 * @author your name (you@domain.com)
 * @brief 用位运算实现加减乘除
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
    while(b != 0){  //直到无进位则停止
        sum=a^b;      //^相当于无进位相加
        b=(a & b)<<1; //进位信息，如果有进位则都为1，向左移动一位为进位
        a=sum;
    }
    return sum;
}

int negNum(int n){
    return add(~n,1);
}

int subtract(int a, int b){ //减法即a+b的相反，b的相反即取反加1
    return add(a,negNum(b));
}

int muti(int a, int b){ //乘法，和整数乘法类似
    int sum=0;
    while(b){
        if((b & 1) != 0){
            sum=add(sum,a);
        }
        a<<=1;
        b>>=1;  //算术右移
    }
    return sum;
}
bool isNeg(int n){
    return n<0;
}

int Div(int a, int b){  //除法
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
    cout<<"减法:"<<subtract(a,b)<<endl;
    cout<<"乘法:"<<muti(a,b)<<endl;
    cout<<"除法:"<<Div(a,b)<<endl;
    system("pause");

    return 0;
}