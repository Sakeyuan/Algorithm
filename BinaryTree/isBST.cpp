/**
 * @file isBST.cpp
 * @author your name (you@domain.com)
 * @brief 二叉搜索树：树所有节点的 左子树的值 < 父节点的值 < 右子树的值 
 * 思路：中序比较，preval为前一个节点的值，前一个节点的值始终小于当前节点的值即可
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
#include<sstream>
#include <limits.h>
using namespace std;
typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {
    }
};

TreeNode* createBT(istringstream& ss) {
    string tmp;
    ss >> tmp;
    if (tmp == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(tmp)); //stoi将tmp转为int
    node->left = createBT(ss);
    node->right = createBT(ss);
    return node;
}
int preVal = INT_MIN;
bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    bool isBST = isValidBST(root->left);
    if (isBST == false) return false;
    if (preVal >= root->val) return false;
    else {
        preVal = root->val;
    }
    isBST = isValidBST(root->right);
    return isBST;
}
int main() {
    TreeNode* root = nullptr;
    string str = "5 4 1 # # 7 # # 8 # #";
    istringstream ss(str);
    root = createBT(ss);
    cout<<isValidBST(root);
    cout << endl;
    system("pause");
    return 0;
}