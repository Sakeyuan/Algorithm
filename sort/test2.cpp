    int res=0;
    void merge(vector<int>&nums,int l,int r,int mid){
        int p1=l;
        int p2=mid+1;
        int p3=0;
        int tmp[r-l+1];
        while(p1<=mid && p2<=r ){
            if(nums[p1] <= nums[p2]){
                tmp[p3++]=nums[p1++];
            }else{
                res+=(mid-p1+1);
                tmp[p3++]=nums[p2++];
            }
        }

        while(p1 <= mid){
            tmp[p3++]=nums[p1++];
        }

        while(p2 <= r){
            tmp[p3++]=nums[p2++];
        }

        //拷贝会原数组
        for(int i=0;i<p3;++i){
            nums[i]=tmp[i];
        }
    }

    void merge_sort(vector<int>&a,int N,int l,int r){
        if(l >= r) return;
        int mid=l+((r-l)>>1);
        merge_sort(a,N,l,mid);      //左边有序
        merge_sort(a,N,mid+1,r);    //右边有序
        merge(a,l,r,mid);         //归并
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        merge_sort(nums,n,0,n-1);
        return res;
    }