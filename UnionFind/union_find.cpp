/*加权并查集算法*/
#include<iostream>
class UNION_FIND{
public:
    UNION_FIND(int N);
    ~UNION_FIND();
    int find_root(int p);
    bool union_root(int p,int q);
    int setNum(){ return count;}  //集合数量

    int* parent;
    int* tSize;
    int count;
};
int UNION_FIND::find_root(int p){
    while(p != parent[p]) p=parent[p]; //寻找根节点
    return p;
}
bool UNION_FIND::union_root(int p,int q){
    int p_root=find_root(p);
    int q_root=find_root(q);
    if(p_root == q_root)  return 0;
    if(tSize[p_root]>tSize[q_root]){    //小的合并到大的上去
        parent[q_root]=p_root;          
        tSize[p_root]+=tSize[q_root];
    }
    else{
        parent[p_root]=q_root;
        tSize[q_root]+=tSize[p_root];
    }
    count--;
    return 1;
}
UNION_FIND::UNION_FIND(int N){
        parent=new int[N];
        tSize=new int[N];
        this->count=N;
        for(int i=0;i<N;i++)    parent[i]=i;
        for(int i=0;i<N;i++)    tSize[i]=1;   
    }
UNION_FIND::~UNION_FIND(){
    delete[] parent;
    delete[] tSize;
}
int main(){
    UNION_FIND uf(10);  //N根据数值最大值决定
    int edges[4][2]={{3,8},{3,4},{8,9},{4,9}}; //四条边，3节点和8节点连接
    
    for (int i = 0; i < 4; i++)
    {
        int x=edges[i][0];
        int y=edges[i][1];
        if(uf.union_root(x,y) == 0){
            std::cout<<"cycle detected\n";
            system("pause");
            exit(1);
        } 
        
    }
    std::cout<<"no cycles detected\n";
    system("pause");
    return 0;
}