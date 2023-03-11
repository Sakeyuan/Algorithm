#include<iostream>
#include<vector>
using namespace std;

int count = 0;
int reversePairs(vector<int>&nums) {
    sort(nums, 0, nums.size() - 1);
    return count;
}

void sort(vector<int>&nums,int left,int right){
    if(left < right){
        int mid = (left+right) / 2;//开始递归划分

        sort(nums,left,mid);//归并排序左部分（left,mid)

        sort(nums,mid+1,right);//归并排序右部分(mid+1,right)
        merge(nums,left,mid,right);//合并
    }
}

void merge(vector<int>&nums, int left, int mid, int right) {
    int i = left;   //左部分首元素
    int j = mid + 1;//右部分首元素
    int t = 0;
    int temp[right-left+1];
    while(i <=mid && j <=right){//在范围之内
        if(nums[i] <= nums[j]){
            temp[t++] = nums[i++];
        }else{
            count += (mid - i + 1);//只需要这行代码
            temp[t++] = nums[j++];
        }
    }

    while (i <= mid){//右边遍历完事了   左边还剩呢
        temp[t++] = nums[i++];
    }
    while( j <= right){//左边遍历完事了   右边还剩了
        temp[t++] = nums[j++];
    }

    t = 0;//将temp中的元素  全部都copy到原数组里边去
    while (left <=right){
        nums[left++] = temp[t++];
    }
}