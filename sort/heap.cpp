#include<iostream>
void swap(int* a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

//给我一个数组，建立大根堆
void heapInsert(int* a,int N,int index){ //不断和父亲比较，一直向上即可
    while (a[index] > a[(index-1)/2])
    {
        swap(a,index,(index-1)/2);
        index = (index-1)/2;
    }            
}

//调整堆，从index位置开始调整，heapSize管理堆大小
void heap_fy(int* a,int N,int index,int heapSize){
    int left = index*2+1;//左孩子
    while(left < heapSize){  //下方有左孩子
        //left+1<heapSize表示有右孩子，largest为孩子和父亲之间的最大值下标,left+1为右孩子
        int largest=(left+1<heapSize) && (a[left]<a[left+1])?left+1:left;//孩子和孩子比较
        largest=a[index] < a[largest] ? largest : index; //父亲和孩子比较
        if(largest == index) break;  //如果父亲的值大,不需要调整
        swap(a,largest,index);
        index = largest;  //index往下走
        left = index*2+1; //左孩子
    }
}

void heap_sort(int* a,int N){
    if(a==NULL || N<2)   return;
    for (int i = 0; i < N; i++)  
        heapInsert(a,N,i);

    int heapSize = N;
    swap(a,0,--heapSize); //大根堆的头和尾交换，因为头最大，调换到末尾处理
    while (heapSize > 0)
    {
        heap_fy(a,N,0,heapSize);
        swap(a,0,--heapSize);
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
    int a[]={-10,12,2,1,3,5,8,-1,0,12};
    int N=sizeof(a)/sizeof(a[0]);
    heap_sort(a,N);
    print(a,N);
    system("pause");
    return 0;
}