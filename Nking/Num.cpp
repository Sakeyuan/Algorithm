/**
 * @file Num.cpp
 * @author your name (you@domain.com)
 * @brief N 皇后问题
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
using namespace std;

bool ok(int *pos,int i,int j){
    for (int k = 0; k < i; k++)  //之前行的皇后
    {
        if(pos[k]==j || abs(pos[k]-j) == abs(i-k)) return false;
    }
    return true;  
}


//来到第i行
//pos[i]表示第i行的皇后放置的列位置
int N(int* pos, int i, int n){
    if(i == n) return 1; //皇后摆到第n行（终止行），则返回一种方法，pos[i]，i前面的皇后移动不共行、不共列、不共斜线，所以i==n就有一种方法
    
    int res=0;
    //摆放第j列
    for(int j=0;j<n;j++){  //j表示列
        if(ok(pos,i,j)){ //ok检查是否和前面的皇后冲突，即在对角线和同一列上
            pos[i]=j;
            res+=N(pos,i+1,n);  //放完前一行后，进入下一行放
        }
    }
    return res;
}
int Num(int n){
    if(n == 0) return 0;
    int pos[4]; //pos[i]的值表示第 i 行皇后的位置摆在第几列
    int i = 0;
    return N(pos,i,n);
} 

int main(){
    int n=0;
    cout<<"请输入N: ";
    cin >> n;
    cout<<"一共有 "<< Num(n) <<" 摆放方法 "<<endl;;
    system("pause");
    return 0;
}