#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main(){
    int a=0xff;
    a=a>>1;
    cout<<a;

    system("pause");
}
