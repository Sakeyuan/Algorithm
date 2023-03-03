/**
 * @file reverseStack.cpp
 * @author your name (you@domain.com)
 * @brief 不使用其他数据结构的情况下，将栈逆序
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include<iostream>
#include<stack>
using namespace std;

/**
 * @brief
 *   getLast获取栈底元素
 * @return int
 */
int getLast(stack<int>&s) {
    int res = s.top(); s.pop();
    if (s.empty())
        return res;
    else {
        int last = getLast(s);
        s.push(res);
        return last;
    }
}

void reverse(stack<int>&s) {
    if (s.empty()) return;
    int i = getLast(s);
    reverse(s);
    s.push(i);
   
}

int main() {
    stack<int>s;
    for (int i = 1; i < 4; ++i) {
        s.push(i);
    }
    reverse(s);
    for (int i = 1; i < 4; ++i) {
        cout << s.top() << " ";
        s.pop();
    }
    system("pause");
    return 0;

}