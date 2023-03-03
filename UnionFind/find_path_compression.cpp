/*路径压缩并查集算法*/
#include<iostream>
class WeightUF{
public:
    WeightUF(int N);
    ~WeightUF();
    int find_root(int p);
    bool union_root(int p,int q);

private:
    int* parent;
    int* rank;
};
int WeightUF::find_root(int p){
    while(p!=parent[p]){
        parent[p]=parent[parent[p]];    //将沿途路径压缩
        p=parent[p];
    }
    return p;
}
bool WeightUF::union_root(int p,int q){
    int p_root=find_root(p);
    int q_root=find_root(q);
    if(p_root==q_root)  return 0;
    //小数连接大树
    else if(rank[p_root]>rank[q_root]) parent[q_root]=p_root;
    else if(rank[p_root]<rank[q_root]) parent[p_root]=q_root;
    else{
        parent[p_root]=q_root;
        rank[q_root]++;
    }
    return 1;
}
WeightUF::WeightUF(int N){
        parent=new int[N];
        rank=new int[N];
        for(int i=0;i<N;i++)    parent[i]=i;
        for(int i=0;i<N;i++)    rank[i]=0;   
    }
WeightUF::~WeightUF(){
    delete[] parent;
    delete[] rank;
}
int main(){
    WeightUF weightUF(10);
    int edges[3][2]={{3,8},{3,4},{8,9}};
    for (int i = 0; i < 3; i++)
    {
        int x=edges[i][0];
        int y=edges[i][1];
        if(weightUF.union_root(x,y)==0){
            std::cout<<"cycle detected\n";
            system("pause");
            exit(1);
        } 
        
    }
    std::cout<<"no cycles detected\n";
    system("pause");
    return 0;
}