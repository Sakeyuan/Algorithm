#include<iostream>
#include<vector>
using namespace std;
int nums[]={5,2,6,1};
int n=sizeof(nums)/sizeof(nums[0]);
int* index=new int[n];
int* tmp=new int[n];
int* tmpIndex=new int[n];
int* res=new int[n];

void merge(int * a,int n,int l,int r,int mid){
    int i=l,j=mid+1;
    int p=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            tmp[p]=a[i];
            tmpIndex[p]=index[i];
            res[index[i]]+=j-mid-1;
            ++i;
            ++p;
        }
        else{
            tmp[p]=a[i];
            tmpIndex[p]=index[i];
            ++j;
            ++p;
        }
        while(i<=mid){
            tmp[p]=a[i];
            tmpIndex[p]=index[i];
            res[index[i]]+=(j-mid-1);
            ++i;
            ++p;
        }
        while(j<=r)
            tmp[p]=a[i];
            tmpIndex[p]=index[i];
            ++j;
            ++p;
        }
        for (int k = 0; k < n; k++)
        {
            index[k]=tmpIndex[k];
        }      
    }

void merge_sort(int * nums,int n,int l,int r){
    if(l>=r) return;
    int mid=l+((r-l)>>1);
    merge_sort(nums,n,l,mid);
    merge_sort(nums,n,mid+1,r);
    merge(nums,n,l,r,mid);     
}
void countSmaller(int * nums,int n) {
    for(int i=0;i<n;i++){
        index[i]=i;
    }
    merge_sort(nums,n,0,n-1);  
}
int main(){
    countSmaller(nums,n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    delete[] res;
    delete[] tmp;
    delete[] tmpIndex;
    delete[] index;
    return 0;
}