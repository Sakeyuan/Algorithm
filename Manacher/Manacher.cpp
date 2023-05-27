/**
 * @file Manacher.cpp
 * @author your name (you@domain.com)
 * @brief һ��������������Ӵ�(i��i'����C�Գ�,RΪ���Ĵ��뾶)
 *  1��i��R��
 *  2) i��R��
 *      a. i' ���İ뾶��R��
 *      b. i' ���İ뾶����ڱ߽���
 *      c. i' ���İ뾶�����R��
 * 
 * ԭ�ַ����� = (ԭ�ַ���-1)/2
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
    int C = -1;       //ֱ������  
    int R = -1;       //�뾶�ұ߽�
    int maxR = -1;
    int maxIndex = -1;
    handleStr(str);
    int n = str.size();
    int RArray[n];  //���İ뾶����
    int start = 0;
    for(int i = 0; i < n; i++){
        //������֤������RArray[2*C-i]Ϊi'�Ļ��İ뾶
        RArray[i] = R > i ? min(RArray[2*C-i],R-i):1;
        while (i + RArray[i] < n &&  i - RArray[i] > -1)   //ͳһ������
        {
            if(str[RArray[i]+i] == str[i-RArray[i]]){
                RArray[i]++;
            }else{  //�޷���չ
                break;
            }
        } 
        if(i+RArray[i] > R){ //R�߽粻������
            R=i+RArray[i];
            C=i;
        }
        //RArray[i]/2��ʾÿ����ĸ���ŵ�ʵ�ʻ���
        //�������Ĵ�
        if(maxR < RArray[i]){
            maxR=RArray[i];
            start = (i-maxR+1)/2;
        }
        
        Max = max(Max,RArray[i]);
    }
    maxString = s.substr(start,maxR-1);
    return Max-1;  //��������ź���Ҫ-1�ſ��Եõ�ԭ���ַ����Ļ��Ĵ�����
}
int main(){
    string str="baabaad";
    cout<<Manacher(str)<<endl;
    cout<<maxString<<endl;

    return 0;
}