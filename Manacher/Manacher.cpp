/**
 * @file Manacher.cpp
 * @author your name (you@domain.com)
 * @brief һ��������������Ӵ�(i��i'����C�Գ�,RΪ���Ĵ��뾶)
 *  1��i��R��
 *  2) i��R��
 *      a. i' ���İ뾶��R��
 *      b. i' ���İ뾶����ڱ߽���
 *      c. i' ���İ뾶�����R��
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
    int Max = -1;
    int C=-1;       //ֱ������  
    int R=-1;       //�뾶�ұ߽�
    handleStr(str);
    int n=str.size();
    int RArray[n];  //���İ뾶����
    for(int i=0; i < n; i++){
        RArray[i]=R > i ? min(RArray[2*C-i],R-i):1;
        while (i + RArray[i] < n &&  i - RArray[i] > -1)   //ͳһ������
        {
            if(str[RArray[i]+i] == str[i-RArray[i]]){
                RArray[i]++;
            }else{  //�޷���չ
                break;
            }
        } 
        if(i+RArray[i] > R){
            R=i+RArray[i];
            C=i;
        }
        Max = max(Max,RArray[i]);
    }
    return Max-1;  //��������ź���Ҫ-1�ſ��Եõ�ԭ���ַ����Ļ��Ĵ�����
}
int main(){
    string str="122132";
    cout<<Manacher(str);
    system("pause");
    return 0;
}