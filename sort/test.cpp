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
        int mid = (left+right) / 2;//��ʼ�ݹ黮��

        sort(nums,left,mid);//�鲢�����󲿷֣�left,mid)

        sort(nums,mid+1,right);//�鲢�����Ҳ���(mid+1,right)
        merge(nums,left,mid,right);//�ϲ�
    }
}

void merge(vector<int>&nums, int left, int mid, int right) {
    int i = left;   //�󲿷���Ԫ��
    int j = mid + 1;//�Ҳ�����Ԫ��
    int t = 0;
    int temp[right-left+1];
    while(i <=mid && j <=right){//�ڷ�Χ֮��
        if(nums[i] <= nums[j]){
            temp[t++] = nums[i++];
        }else{
            count += (mid - i + 1);//ֻ��Ҫ���д���
            temp[t++] = nums[j++];
        }
    }

    while (i <= mid){//�ұ߱���������   ��߻�ʣ��
        temp[t++] = nums[i++];
    }
    while( j <= right){//��߱���������   �ұ߻�ʣ��
        temp[t++] = nums[j++];
    }

    t = 0;//��temp�е�Ԫ��  ȫ����copy��ԭ�������ȥ
    while (left <=right){
        nums[left++] = temp[t++];
    }
}