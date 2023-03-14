/*·��ѹ�����鼯�㷨*/
#include<iostream>
#include<vector>
class UNION_FIND{
public:
    UNION_FIND(int N);
    ~UNION_FIND();
    int find_root(int p);     
    bool union_root(int p,int q);
    int getCount(){ return count;}  //��������
    
    std::vector<int> parent;
    std::vector<int> rank;  //���ĸ߶�
    int count; //��������
};
int UNION_FIND::find_root(int p){
    while(p != parent[p]){  //�����Ǹ��ڵ��ʱ������·�Ҹ��ڵ��ÿ���ڵ㶼ѹ��
        parent[p] = parent[parent[p]];    //����;·��ѹ��
        p=parent[p];
    }
    return p;
}
bool UNION_FIND::union_root(int p,int q){
    int p_root=find_root(p);
    int q_root=find_root(q);
    if(p_root==q_root)  return 0;
    //С�����Ӵ����߶Ȳ�����
    else if(rank[p_root]>rank[q_root]) parent[q_root]=p_root;
    else if(rank[p_root]<rank[q_root]) parent[p_root]=q_root;
    else{
        parent[p_root]=q_root;
        rank[q_root]++; //���ڵ�ͳ�Ƹ߶�
    }
    count--;
    return 1;
}


UNION_FIND::UNION_FIND(int N){

        this->count=N;
        for(int i=0;i<N;i++)    parent.push_back(i);
        for(int i=0;i<N;i++)    rank.push_back(0);   
    }

int main(){
    UNION_FIND uf(10);
    int edges[3][2]={{3,8},{3,4},{8,9}};
    for (int i = 0; i < 3; i++)
    {
        int x=edges[i][0];
        int y=edges[i][1];
        if(uf.union_root(x,y)==0){
            std::cout<<"cycle detected\n";
            system("pause");
            exit(1);
        } 
        
    }
    std::cout<<"no cycles detected\n";
    system("pause");
    return 0;
}