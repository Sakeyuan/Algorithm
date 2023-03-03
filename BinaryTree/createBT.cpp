#include<iostream>
#include<sstream>
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
    TreeNode* node = new TreeNode(stoi(tmp)); //stoi½«tmp×ªÎªint
    node->left = createBT(ss);
    node->right = createBT(ss);
    return node;
}
int main() {
    TreeNode* root = nullptr;
    string str = "5 1 # # 4 3 # # 6 # #";
    istringstream ss(str);
    root = createBT(ss);

    cout << endl;
    system("pause");
    return 0;
}