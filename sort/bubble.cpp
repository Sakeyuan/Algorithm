#include<iostream>
void swap(int* a,int i,int j){
    /*异或的性质：
    1.0^N=N  2.N^N=0 
    3.异或满足交换律和结合律 a^b=b^a  (a^b)^c=a^(b^c)
    */
    a[i]=a[i]^a[j];  //a[i]=a[i]^a[j]  a[j]=a[j]
    a[j]=a[i]^a[j];  //a[j]=a[i]^a[j]^a[j] 所以a[j]=a[i],0^a[i]
    a[i]=a[i]^a[j];  //a[i]=a[i]^a[j]^a[i] 所以a[i]=a[j],0^a[j]
    
    /****这里不建议这样写，因为当有值相同异或的时候会变成0***/
}
void bubble_sort(int* a,int N){
    if(a==NULL || N<2)   return;
    //每次排序，外层循环都排好最后一个元素，所以内层循环经过N-1 N-2 N-3 .... 1 轮
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