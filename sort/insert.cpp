#include<iostream>
void swap(int* a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void insert_sort(int* a,int N){
    if(a==NULL || N<2)   return;
    for(int i = 1;i < N; ++i){
        for (int j = i-1; j >=0 && a[j]>a[j+1]; --j)
            swap(a,j,j+1);
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
    int a[]={2,141,23,41,1,0,-1,0,8,10,100,26,1};
    int N=sizeof(a)/sizeof(a[0]);
    insert_sort(a,N);
    print(a,N);
    system("pause");
    return 0;
}