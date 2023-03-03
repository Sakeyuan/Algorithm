#include<iostream>
int num[3]={0,0,0};
//打印数组中两个数出现奇数次的数
void printOddNum2(int* a, int N){
    int tmp=0;
    for(int i=0;i<N;++i){
        tmp^=a[i];        
    }
    //tmp=num1^num2
    //num1≠num2，所以tmp的二进制中必须有一个1，且tmp≠
    //提取二进制最右边的1
    int rightOne=tmp & (~tmp+1);
    for(int i=0;i<N;++i){
        if((a[i] & rightOne)==0) //提取一边，要么是a，要么是b
            num[1]^=a[i];
    }
    num[2]=tmp^num[1];
}
int main(){
    int a[]={1,2,3,1,2,3,3,4,4,3,5,6,4,6};
    printOddNum2(a,sizeof(a)/sizeof(a[0]));
    std::cout<<"num1="<<num[1]<<std::endl;
    std::cout<<"num2="<<num[2]<<std::endl;
    system("pause");
    return 0;
}