#include<iostream>
//打印数组中一个数出现奇数次的数
int printOddNum1(int* a, int N){
    int num=0;
    for(int i=0;i<N;++i){
        num^=a[i];        
    }
    return num;
}
int main(){
    int a[]={1,2,3,1,2,3,3,4,4,3,5};
    std::cout<<printOddNum1(a,sizeof(a)/sizeof(a[0]))<<std::endl;
    system("pause");
    return 0;
}