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
    int less = l-1; //��߽�
    int more =r;    //�ұ߽�
    while(l<more){
        if(a[l]<a[r]){
            swap(a,++less,l++);  //��չ��߽�
        }
        else if(a[l]>a[r]){
            swap(a,--more,l); //��չ�ұ߽磬lָ�벻������Ϊ�ոջ���������û���ٴαȽ�
        }
        else  l++; //�м�=�����ƶ�ָ�뼴��
    }

    swap(a,more,r);
    p[0]=less+1;
    p[1]=more;
}
void quick_sort(int* a,int N,int l,int r){
    int p[2];
   if(l<r) {
        swap(a,l+(int)(rand()%(r-l+1)),r); //���ѡ��[l,r-l+1)֮�����
        partition(a,N,l,r,p);
        quick_sort(a,N,l,p[0]-1); //<��������
        quick_sort(a,N,p[1]+1,r); //>���������м�Ϊ����Ԭ������
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
    srand(time(0)); //�������
    quick_sort(a,N,0,N-1);
    print(a,N);
    system("pause");
    return 0;
}