/**
 * @file KMP.cpp
 * @author your name (you@domain.com)
 * @brief str2 ƥ��str1
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
    next[1]=0; //�ַ������岻��
    int i=2;  //��2λ�ÿ�ʼ
    int cn=0; //�Ƚ��ַ���λ��
    while(i < str.size()){
        if(str[i] == str[cn]){
            next[i++]=++cn;
        }
        else if(cn>0){ //��i-1�ַ���ƥ��
            cn=next[cn];
        }else{  //����ƥ��
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
    int i1=0; //st1ָ��
    int i2=0; //st2ָ��
    while (i1<str1.size() && i2<str2.size())
    {
        if(str1[i1]==str2[i2]){  //�ַ�ƥ��
            i1++;
            i2++;
        }
        else if(next[i2] == -1){ //��i2 == 0 ��������ͷ��,i2�Ѿ�������ͷ�ˣ���û��ƥ�䵽������Ҫi1�ƶ�
            i1++;
        }
        else{
            i2=next[i2];
        }
    }
    //i1����i2Խ��
    return i2 == str2.size()?i1-i2:-1;
     
}
int main(){
    string str1="31123";
    string str2="12";
    cout<<"��"<<KMP(str1,str2)<<"�±꿪ʼƥ��"<<endl;
    system("pause");
    return 0;
}