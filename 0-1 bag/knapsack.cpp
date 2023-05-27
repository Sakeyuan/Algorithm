#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5;    //��Ʒ��������Ʒ��Ϊȡ���ǲ�ȡ
const int W = 20;   //�����������20
int weight[N] = {2,3,4,5,9};
int value[N] = {3,4,5,8,10};

//��ά����
void knapsack1(){
    int dp[N+1][W+1]={0};
    //��ʼ��
    for (int j = 2; j <= W; j++)
    {
        dp[0][j] = value[0];
    }
 
    for(int i = 1; i<=N; i++){  
        for(int j = 0; j<=W; j++){
            if(weight[i] > j){      //��Ʒi�������ȱ�����ʣ��������װ����
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    cout<<dp[N][W]<<endl;
}

//һά����
void knapsack2(){
    int dp[W+1] = {0};
    for (int i = 0; i < N; i++)  //������Ʒ
    {
        for (int j = W; j >= weight[i]; j--)  //�Ӻ���ǰ������Ϊ��ֻ��һ����Ʒ�������ǰ�������������˶�Σ�������0-1����
        {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);   
        }
        
    }
    cout<<dp[W]<<endl;
}

int main(){
    knapsack1();
    knapsack2();
    system("pause");
    return 0;
}
