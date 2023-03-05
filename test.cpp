#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int trap(int* height,int n) {
    int res = 0;
    int leftMax[n];
    int rightMax[n];
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
        rightMax[n - 1 - i] = max(rightMax[n - i], height[n - i]);
    }
    for (int i = 0; i < n; ++i) {
        res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
}

int main() {
    int num[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    trap(num,sizeof(num)/sizeof(num[0]));
    return 0;
}