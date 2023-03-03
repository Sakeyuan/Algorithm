/**
 * @file KMP.cpp
 * @author your name (you@domain.com)
 * @brief str2 匹配str1
 * @version 0.1
 * @date 2023-03-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getNext(const string str,int* next){
    if(str.size() == 1) return;
    next[0]=-1;
    next[1]=0; //字符串整体不算
    int i=2;  //从2位置开始
    int cn=0; //比较字符的位置
    while(i < str.size()){
        if(str[i] == str[cn]){
            next[i++]=++cn;
        }
        else if(cn>0){ //和i-1字符不匹配
            cn=next[cn];
        }else{  //都不匹配
            next[i++]=0;
        }
    }
}
int KMP(const string str1,const string str2){
    if(str1.empty() ||str2.empty() || str1.size() < str2.size()){
        return -1;
    }
    int next[str2.size()];
    getNext(str2,next);
    int i1=0; //st1指针
    int i2=0; //st2指针
    while (i1<str1.size() && i2<str2.size())
    {
        if(str1[i1]==str2[i2]){  //字符匹配
            i1++;
            i2++;
        }
        else if(next[i2] == -1){ //即i2 == 0 （跳到开头）,i2已经跳到开头了，还没有匹配到，则需要i1移动
            i1++;
        }
        else{
            i2=next[i2];
        }
    }
    //i1或者i2越界
    return i2 == str2.size()?i1-i2:-1;
     
}
int main(){
    string str1="31123";
    string str2="12";
    cout<<"从"<<KMP(str1,str2)<<"下标开始匹配"<<endl;
    system("pause");
    return 0;
}