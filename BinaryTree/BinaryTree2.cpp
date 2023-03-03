//�ǵݹ������
#include<iostream>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;
static int i = -1;
typedef struct Node
{
    char data;
    struct Node* lChild;
    struct Node* rChild;
}*tree, treeNode;
void createBinaryTree(tree& root, char* a) {
    ++i;
    if (a[i] == '#') {
        root = NULL;
        return;
    }
    else {
        root = new treeNode;
        root->data = a[i];
        std::cout << root->data << " ";
        createBinaryTree(root->lChild, a);
        std::cout << root->data << " ";
        createBinaryTree(root->rChild, a);
        std::cout << root->data << " ";
    }
}

//������ȱ���
void widePrint(tree& root) {
    if (root == NULL) return;
    queue<tree>q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        cout << root->data << " ";
        if (root->lChild != NULL) q.push(root->lChild);
        if (root->rChild != NULL) q.push(root->rChild);
    }
}

//�����
int maxWidth(tree& root) {
    if (root == NULL) return 0;
    queue<tree>q;
    unordered_map<tree, int>m;
    int curLevel = 1;
    int curLevelNodes = 0;
    int maxWidth = 0;
    q.push(root);
    m.emplace(pair<tree, int>(root, 1));
    while (!q.empty()) {
        root = q.front();
        q.pop();
        int curNodeLevel = m.at(root);
        if (curLevel == curNodeLevel) {
            curLevelNodes++;
        }
        else {           
            curLevel++;
            curLevelNodes = 1;
        }
        maxWidth = max(curLevelNodes, maxWidth); 
        if (root->lChild != NULL) {
            m.emplace(pair<tree, int>(root->lChild, curLevel + 1));
            q.push(root->lChild);
        }
        if (root->rChild != NULL) {
            m.emplace(pair<tree, int>(root->rChild, curLevel + 1));
            q.push(root->rChild);
        }
    }
    return maxWidth;
}

//��������㷨���������
int maxDepth(tree &root) {
    if (root == NULL) return 0;
    queue<tree>q;
    int maxDepth = 0;
    q.push(root);
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize>0)
        {
            root = q.front();
            q.pop();
            qSize--;        
            if (root->lChild != NULL) q.push(root->lChild);
            if (root->rChild != NULL) q.push(root->rChild);
        }
        maxDepth++;
    }
    return maxDepth;
}
//�������(������ȱ���)
/**
 * 1)��ջ�е���һ���ڵ�
 * 2����ӡ
 * 3)���Һ���ѹ��ջ��������ѹ��ջ
 * 4)�ظ�����1��2��3����
 */
void DLR(tree& root) {
    if (root == NULL) return;
    stack<tree>stk;
    stk.push(root);
    while (!stk.empty())
    {
        root = stk.top();
        stk.pop();
        cout << root->data << " ";
        if ((root->rChild) != NULL) {
            stk.push(root->rChild);
        }
        if ((root->lChild) != NULL) {
            stk.push(root->lChild);
        }
    }
}

//�������
/**
 * ��������߽��ջ
 * ���ε����Ĺ����д�ӡ��Ȼ����ҽڵ��ظ���������
 */
void LDR(tree& root) {
    if (root == NULL) return;
    //�ݹ����е�һ�γ��ֵ�λ��
    stack<tree>s;
    while (!s.empty() || (root != NULL))
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->lChild;
        }
        else {
            root = s.top();
            s.pop();
            cout << root->data << " ";
            root = root->rChild;
        }
    }
}

//�������
void LRD(tree& root) {
    if (root == NULL) return;
    stack<tree>s1;
    stack<tree>s2;
    s1.push(root);
    while (!s1.empty()) {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->lChild != nullptr) s1.push(root->lChild);
        if (root->rChild != nullptr) s1.push(root->rChild);
    }
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }

}
int main() {
    char a[] = { 'A','B','C','G','#','#','H','#','#','#','D','E','I','#','#','J','#','#','F','K','#','#','L','#','#'}; //�ݹ���A B C C C B B A D D E E E D A
    tree root = nullptr;
    createBinaryTree(root, a);
    std::cout << std::endl << "������ȱ���:";
    //widePrint(root);
    //std::cout << std::endl << "�����:";
    //cout << maxWidth(root);
    std::cout << std::endl << "������:";
    cout << maxDepth(root);
    std::cout << std::endl << "�������:";
    DLR(root);
    std::cout << std::endl << "�������:";
    LDR(root);
    std::cout << std::endl << "�������:";
    LRD(root);
    std::cout << std::endl;
    system("pause");
    return 0;
}