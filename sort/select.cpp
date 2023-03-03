#include<iostream>
void swap(int* a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void select_sort(int* a,int N){
    if(a==NULL || N<2)   return;
    for(int i = 0;i < N; ++i){
        int minIndex=i;
        for (int j = i+1; j < N; ++j)
        {
            if(a[minIndex] > a[j])  minIndex=j;
        }
        swap(a,minIndex,i);
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
    select_sort(a,N);
    print(a,N);
    system("pause");
    return 0;
}