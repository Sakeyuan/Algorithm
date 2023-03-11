/**
 * @file walkWay.cpp
 * @author your name (you@domain.com)
 * @brief 一个人从当前位置固定k步走到target可以有多少种方法
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief
 * 暴力递归
 * @param a 总共1~n个位置
 * @param n
 * @param target 目标位置
 * @param rest 剩余步数
 * @param cur 当前步数
 * @return int
 */
int walkWay(int* a, int n, int target, int rest, int cur) {
    //base case
    if (rest == 0) {
        return cur == target ? 1 : 0;
    }

    if (cur == 1) {
        return walkWay(a, n, target, rest - 1, cur + 1);  //走到开头位置，需要前进
    }

    if (cur == n) {
        return walkWay(a, n, target, rest - 1, cur - 1);  //走到末尾位置, 需要后退    
    }

    return walkWay(a, n, target, rest - 1, cur - 1) + walkWay(a, n, target, rest - 1, cur + 1); //向左走和向右走
}




/**
 * @brief
 * 记忆搜索，在递归版本的基础上加记忆数组缓存,去掉重复搜索
 * @param a 总共1~n个位置
 * @param n
 * @param target 目标位置
 * @param rest 剩余步数
 * @param cur 当前位置
 * @return int
 */
int walkWay2(int* a, int n, int target, int rest, int cur, vector<vector<int>>& dp) {

    //base case
    if (rest == 0) {
        dp[rest][cur] = cur == target ? 1 : 0;
        return dp[rest][cur];
    }

    if (cur == 1) {
        dp[rest][cur] = walkWay(a, n, target, rest - 1, cur + 1);  //走到开头位置，需要前进
        return dp[rest][cur];
    }

    else if (cur == n) {
        dp[rest][cur] = walkWay(a, n, target, rest - 1, cur - 1);  //走到末尾位置, 需要后退   
        return dp[rest][cur];
    }

    dp[rest][cur] = walkWay(a, n, target, rest - 1, cur - 1) + walkWay(a, n, target, rest - 1, cur + 1); //向左走和向右走
    return dp[rest][cur];
}

/**
 * @brief
 * 动态规划(严格表结构),观测依赖，填表格
 * @param a 总共1~n个位置
 * @param n
 * @param target 目标位置
 * @param rest 剩余步数
 * @param cur 当前步数
 * @return int
 */
int walkWay3(int* a, int n, int target, int rest, int cur, vector<vector<int>>& dp) {
    //base case
    // if(rest == 0){
    //     return cur == target ? 1:0; 
    // }
    //根据递归求解, 因为从1位置开始，所以i开始为0
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 0;
    }
    dp[1][target] = 1;
    // if(cur == 1){
    //     return walkWay(a,n,target,rest-1,cur+1);  //走到开头位置，需要前进
    // }
    // if(cur == n){
    //     return walkWay(a,n,target,rest-1,cur-1);  //走到末尾位置, 需要后退    
    // }

    // return walkWay(a,n,target,rest-1,cur-1) + walkWay(a,n,target,rest-1,cur+1); //向左走和向右走

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j + 1]; //依赖于右上角的值
            }
            else if (j == n) {
                dp[i][j] = dp[i - 1][j - 1]; //依赖左上角的值
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i-1][j + 1];
            }
        }
    }
    return dp[rest][target];
}



int main() {
    int a[] = {1,2,3,4,5};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 4;
    int rest = 4;
    int cur = 2;
    vector<vector<int>>dp(n+1, vector<int>(n+1)); //记忆数组
    cout << walkWay(a, n, target, rest, cur)<<endl;
    cout << walkWay2(a, n, target, rest, cur, dp)<<endl;   
    cout << walkWay3(a, n, target, rest, cur, dp) << endl;
    system("pause");
    return 0;
}