/**
 * @file Manacher.cpp
 * @author your name (you@domain.com)
 * @brief 一般用于求最长回文子串(i和i'关于C对称,R为回文串半径)
 *  1）i在R外
 *  2) i在R内
 *      a. i' 回文半径在R内
 *      b. i' 回文半径左侧在边界上
 *      c. i' 回文半径左侧在R外
 * 
 * 原字符长度 = (原字符串-1)/2
 * 
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;

string maxString = "";
void handleStr(string& str){
    string tmp="";
    for(int i=0; i<str.size(); i++){
        tmp+="#";
        tmp+=str[i];
    }
    tmp += "#";
    str=tmp;
}
int Manacher(string str){
    string s(str);
    int Max = -1;
    int C = -1;       //直径中心  
    int R = -1;       //半径右边界
    int maxR = -1;
    int maxIndex = -1;
    handleStr(str);
    int n = str.size();
    int RArray[n];  //回文半径数组
    int start = 0;
    for(int i = 0; i < n; i++){
        //不用验证的区域，RArray[2*C-i]为i'的回文半径
        RArray[i] = R > i ? min(RArray[2*C-i],R-i):1;
        while (i + RArray[i] < n &&  i - RArray[i] > -1)   //统一往外扩
        {
            if(str[RArray[i]+i] == str[i-RArray[i]]){
                RArray[i]++;
            }else{  //无法扩展
                break;
            }
        } 
        if(i+RArray[i] > R){ //R边界不断右移
            R=i+RArray[i];
            C=i;
        }
        //RArray[i]/2表示每个字母符号的实际回文
        //求出最长回文串
        if(maxR < RArray[i]){
            maxR=RArray[i];
            start = (i-maxR+1)/2;
        }
        
        Max = max(Max,RArray[i]);
    }
    maxString = s.substr(start,maxR-1);
    return Max-1;  //加特殊符号后需要-1才可以得到原来字符串的回文串长度
}
int main(){
    string str="baabaad";
    cout<<Manacher(str)<<endl;
    cout<<maxString<<endl;

    return 0;
}