#include<iostream>
void merge_sort(int* a,int N,int l,int r);
void merge(int* a,int N,int l,int r,int mid);

void merge_sort(int* a,int N,int l,int r){
    if(l >= r) return;
    int mid=l+((r-l)>>1);
    merge_sort(a,N,l,mid);      //左边有序
    merge_sort(a,N,mid+1,r);    //右边有序
    merge(a,N,l,r,mid);         //归并
}
void merge(int* a,int N,int l,int r,int mid){
    int tmp[r-l+1];
    int p1=l;
    int p2=mid+1;
    int p3=0;
    
    while (p1<=mid && p2<=r)
        tmp[p3++]=a[p1]<=a[p2]?a[p1++]:a[p2++];
    
    //左边还剩下
    while (p1<=mid)
        tmp[p3++]=a[p1++];
    
    //右边还有剩下
    while (p2<=r)
        tmp[p3++]=a[p2++];
    
    //将排序好的放回原数组
    for (int i = 0; i < p3; i++)  //注意这里的是i<p3,而不是N
        a[l+i]=tmp[i];
}
void print(int* a,int N){
    for (int i = 0; i < N; ++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    int a[]={2,141,23,41,9};
    int N=sizeof(a)/sizeof(a[0]);
    merge_sort(a,N,0,N-1);
    print(a,N);
    system("pause");
    return 0;
}