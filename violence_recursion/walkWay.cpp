/**
 * @file walkWay.cpp
 * @author your name (you@domain.com)
 * @brief һ���˴ӵ�ǰλ�ù̶�k���ߵ�target�����ж����ַ���
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
 * �����ݹ�
 * @param a �ܹ�1~n��λ��
 * @param n
 * @param target Ŀ��λ��
 * @param rest ʣ�ಽ��
 * @param cur ��ǰ����
 * @return int
 */
int walkWay(int* a, int n, int target, int rest, int cur) {
    //base case
    if (rest == 0) {
        return cur == target ? 1 : 0;
    }

    if (cur == 1) {
        return walkWay(a, n, target, rest - 1, cur + 1);  //�ߵ���ͷλ�ã���Ҫǰ��
    }

    if (cur == n) {
        return walkWay(a, n, target, rest - 1, cur - 1);  //�ߵ�ĩβλ��, ��Ҫ����    
    }

    return walkWay(a, n, target, rest - 1, cur - 1) + walkWay(a, n, target, rest - 1, cur + 1); //�����ߺ�������
}




/**
 * @brief
 * �����������ڵݹ�汾�Ļ����ϼӼ������黺��,ȥ���ظ�����
 * @param a �ܹ�1~n��λ��
 * @param n
 * @param target Ŀ��λ��
 * @param rest ʣ�ಽ��
 * @param cur ��ǰλ��
 * @return int
 */
int walkWay2(int* a, int n, int target, int rest, int cur, vector<vector<int>>& dp) {

    //base case
    if (rest == 0) {
        dp[rest][cur] = cur == target ? 1 : 0;
        return dp[rest][cur];
    }

    if (cur == 1) {
        dp[rest][cur] = walkWay(a, n, target, rest - 1, cur + 1);  //�ߵ���ͷλ�ã���Ҫǰ��
        return dp[rest][cur];
    }

    else if (cur == n) {
        dp[rest][cur] = walkWay(a, n, target, rest - 1, cur - 1);  //�ߵ�ĩβλ��, ��Ҫ����   
        return dp[rest][cur];
    }

    dp[rest][cur] = walkWay(a, n, target, rest - 1, cur - 1) + walkWay(a, n, target, rest - 1, cur + 1); //�����ߺ�������
    return dp[rest][cur];
}

/**
 * @brief
 * ��̬�滮(�ϸ��ṹ),�۲�����������
 * @param a �ܹ�1~n��λ��
 * @param n
 * @param target Ŀ��λ��
 * @param rest ʣ�ಽ��
 * @param cur ��ǰ����
 * @return int
 */
int walkWay3(int* a, int n, int target, int rest, int cur, vector<vector<int>>& dp) {
    //base case
    // if(rest == 0){
    //     return cur == target ? 1:0; 
    // }
    //���ݵݹ����, ��Ϊ��1λ�ÿ�ʼ������i��ʼΪ0
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 0;
    }
    dp[1][target] = 1;
    // if(cur == 1){
    //     return walkWay(a,n,target,rest-1,cur+1);  //�ߵ���ͷλ�ã���Ҫǰ��
    // }
    // if(cur == n){
    //     return walkWay(a,n,target,rest-1,cur-1);  //�ߵ�ĩβλ��, ��Ҫ����    
    // }

    // return walkWay(a,n,target,rest-1,cur-1) + walkWay(a,n,target,rest-1,cur+1); //�����ߺ�������

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j + 1]; //���������Ͻǵ�ֵ
            }
            else if (j == n) {
                dp[i][j] = dp[i - 1][j - 1]; //�������Ͻǵ�ֵ
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
    vector<vector<int>>dp(n+1, vector<int>(n+1)); //��������
    cout << walkWay(a, n, target, rest, cur)<<endl;
    cout << walkWay2(a, n, target, rest, cur, dp)<<endl;   
    cout << walkWay3(a, n, target, rest, cur, dp) << endl;
    system("pause");
    return 0;
}