#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
void swap(int* a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
} 
void partition(int* a,int N,int l,int r,int *p){
    int less = l-1; //左边界
    int more =r;    //右边界
    while(l<more){
        if(a[l]<a[r]){
            swap(a,++less,l++);  //扩展左边界
        }
        else if(a[l]>a[r]){
            swap(a,--more,l); //扩展右边界，l指针不动，因为刚刚换过来，还没有再次比较
        }
        else  l++; //中间=区域，移动指针即可
    }

    swap(a,more,r);
    p[0]=less+1;
    p[1]=more;
}
void quick_sort(int* a,int N,int l,int r){
    int p[2];
   if(l<r) {
        swap(a,l+(int)(rand()%(r-l+1)),r); //随机选择[l,r-l+1)之间的数
        partition(a,N,l,r,p);
        quick_sort(a,N,l,p[0]-1); //<区域排序
        quick_sort(a,N,p[1]+1,r); //>区域排序，中间为等于袁、区域
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
    int a[]={3,2,5,4,6,4,424,414,42,43,0,-12,-1,-2};
    int N=sizeof(a)/sizeof(a[0]);
    srand(time(0)); //随机种子
    quick_sort(a,N,0,N-1);
    print(a,N);
    system("pause");
    return 0;
}