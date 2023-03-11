/**
 * @file inversePair.cpp
 * @author your name (you@domain.com)
 * @brief ���ù鲢����˼�룬�������
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
using namespace std;
int res=0;
void merge(int* a,int n,int l,int mid,int r){
    int p1=l;
    int p2=mid+1;
    int p3=0;
    int tmp[n];
    while(p1 <= mid && p2<= r){
        if(a[p1] <= a[p2]){  //=�ȿ������
            tmp[p3++] = a[p1++];
        }else{
            res+=(mid-p1+1);  //�����±�������
            tmp[p3++] = a[p2++];
        }
    }

    while (p1 <= mid)
    {
        tmp[p3++] = a[p1++];
    }
    
    while (p2 <= r)
    {
        tmp[p3++] = a[p2++];
    }
    //������ԭ������
    p3 = 0;
    while (l <= r )
    {
        a[l++] = tmp[p3++];
    }
}
void merge_sort(int* a,int n,int l,int r){
     if(l >= r) return;
     int mid=(l+r)/2;
    merge_sort(a,n,l,mid);
    merge_sort(a,n,mid+1,r);
    merge(a,n,l,mid,r);
}
int inversePair(int* a,int n){
    merge_sort(a,n,0,n-1);
    return res;
}
int main(){
    int nums[]={7,5,6,4};
    cout<<"�������:"<<inversePair(nums,sizeof(nums)/sizeof(nums[0]))<<endl;
    system("pause");
    return 0;
}