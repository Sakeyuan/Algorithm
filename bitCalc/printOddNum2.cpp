#include<iostream>
int num[3]={0,0,0};
//��ӡ���������������������ε���
void printOddNum2(int* a, int N){
    int tmp=0;
    for(int i=0;i<N;++i){
        tmp^=a[i];        
    }
    //tmp=num1^num2
    //num1��num2������tmp�Ķ������б�����һ��1����tmp��
    //��ȡ���������ұߵ�1
    int rightOne=tmp & (~tmp+1);
    for(int i=0;i<N;++i){
        if((a[i] & rightOne)==0) //��ȡһ�ߣ�Ҫô��a��Ҫô��b
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