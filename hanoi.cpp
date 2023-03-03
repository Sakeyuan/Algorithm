#include<iostream>
using namespace std;

//目标：1-i 从 from 放置到 to 圆盘
void hanoi(int i,string from,string to,string other){
    if(i == 1) cout<<"把 1 从 "<<from<<" 移动到 "<<to<<endl;
    else{
        //把第 i-1 个盘从 from 放置到 other 盘
        hanoi(i-1,from,other,to);
        cout<<"把 "<<i<<" 从 "<<from<<" 移动到 " << to<<endl;
        //把第 i 个盘从 from 放置到 to 盘
        hanoi(i-1,other,to,from);
    }
}
int main(){
    int n=0;
    cin >> n;
    if(n>0) 
        hanoi(n,"左盘","右盘","中盘");

    system("pause");
    return 0;
}