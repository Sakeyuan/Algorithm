/**
 * @file getMax.cpp
 * @author your name (you@domain.com)
 * @brief 不使用比较的方法，得出大的一方
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
using namespace std;

//相同返回0，不同为1
bool flip(int n){
    return n^1;
}

//判断n符号位，0为负数，1为正数
bool sign(int n){
    return flip((n >> 31) & 1);
}

int getMax(const int a,const int b){
    int c=a-b;
    bool sa=sign(a);
    bool sb=sign(b);
    bool sc=sign(c);
    bool diff_ab=sa^sb;         //a和b符号不一样
    bool same_ab=flip(diff_ab); //a和b一样
    bool return_a=diff_ab*sa + same_ab*sc; //1)a和b符号不一样，a要大于0，才返回a   2）a和b符号一样，a-b大于0
    bool return_b=flip(return_a);
    return a*return_a+b*return_b;   //+号两边选其一
}

int main(){
    int a=100;
    int b=10;
    cout<<getMax(a,b);
    system("pause");
    return 0;
}