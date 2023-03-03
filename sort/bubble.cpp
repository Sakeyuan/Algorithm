#include<iostream>
void swap(int* a,int i,int j){
    /*�������ʣ�
    1.0^N=N  2.N^N=0 
    3.������㽻���ɺͽ���� a^b=b^a  (a^b)^c=a^(b^c)
    */
    a[i]=a[i]^a[j];  //a[i]=a[i]^a[j]  a[j]=a[j]
    a[j]=a[i]^a[j];  //a[j]=a[i]^a[j]^a[j] ����a[j]=a[i],0^a[i]
    a[i]=a[i]^a[j];  //a[i]=a[i]^a[j]^a[i] ����a[i]=a[j],0^a[j]
    
    /****���ﲻ��������д����Ϊ����ֵ��ͬ����ʱ�����0***/
}
void bubble_sort(int* a,int N){
    if(a==NULL || N<2)   return;
    //ÿ���������ѭ�����ź����һ��Ԫ�أ������ڲ�ѭ������N-1 N-2 N-3 .... 1 ��
    for (int i = N-1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(a[j]>a[j+1]) swap(a,j,j+1);
        }        
    }
    
}
void print(int* a,int N){
    for (int i = 0; i < N; ++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    int a[]={2,141,23,41,1,0,-1,0,8,10,100,26};
    int N=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,N);
    print(a,N);
    system("pause");
    return 0;
}