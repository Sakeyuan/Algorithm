#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5;    //物品数量，物品分为取还是不取
const int W = 20;   //背包最大容量20
int weight[N] = {2,3,4,5,9};
int value[N] = {3,4,5,8,10};

//二维数组
void knapsack1(){
    int dp[N+1][W+1]={0};
    //初始化
    for (int j = 2; j <= W; j++)
    {
        dp[0][j] = value[0];
    }
 
    for(int i = 1; i<=N; i++){  
        for(int j = 0; j<=W; j++){
            if(weight[i] > j){      //物品i的重量比背包的剩余容量大，装不下
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    cout<<dp[N][W]<<endl;
}

//一维数组
void knapsack2(){
    int dp[W+1] = {0};
    for (int i = 0; i < N; i++)  //遍历物品
    {
        for (int j = W; j >= weight[i]; j--)  //从后往前遍历，为了只放一次物品，如果从前往后遍历，则放了多次，不符合0-1背包
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
