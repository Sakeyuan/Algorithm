#include<iostream>
void swap(int* a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
//���������
void heapInsert(int* a,int N,int index){
    while (a[index]>a[(index-1)/2])
    {
        swap(a,index,(index-1)/2);
        index=(index-1)/2;
    }            
}
//�����ѣ���indexλ�ÿ�ʼ����
void heap_fy(int* a,int N,int index,int heapSize){
    int left=index*2+1;//����
    while(left<heapSize){
        //largestΪ���Ӻ͸���֮������ֵ�±�,left+1Ϊ�Һ���
        int largest=(left+1<heapSize) && (a[left]<a[left+1])?left+1:left;//���Ӻͺ��ӱȽ�
        largest=a[index]<a[largest]?largest:index; //���׺ͺ��ӱȽ�
        if(largest==index) break;  //������׵�ֵ��,����Ҫ����
        swap(a,largest,index);
        index=largest; 
        left=index*2+1;
    }
}
void heap_sort(int* a,int N){
    if(a==NULL || N<2)   return;
    for (int i = 0; i < N; i++)  
        heapInsert(a,N,i);
    int heapSize =N;
    swap(a,0,--heapSize); //����ѵ�ͷ��β��������Ϊͷ��󣬵�����ĩβ����
    while (heapSize>0)
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
    int a[]={2,141,23,41,1,0,-1,0,8,10,100,26};
    int N=sizeof(a)/sizeof(a[0]);
    heap_sort(a,N);
    print(a,N);
    system("pause");
    return 0;
}