#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/**
 * @brief 单链表排序
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* partion(ListNode* head, ListNode* tail) {
    ListNode* pivot = head;
    ListNode* p = head;
    ListNode* q = head->next;
    while (q != tail->next) {
        if (q->val < pivot->val) {
            p = p->next;
            std::swap(q->val, p->val);
        }
        q = q->next;
    }
    swap(p->val, pivot->val);
    return p;
}

void quick_sort_list(ListNode* head, ListNode* tail) {
    if (head == nullptr || head->next == nullptr || head == tail) { //链表长度为0或者1
        return;
    }
    ListNode* p = partion(head, tail);
    quick_sort_list(head, p);
    quick_sort_list(p->next, tail);
}

ListNode* quickSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) { //链表长度为0或者1
        return head;
    }
    ListNode* tail = head;
    while (tail->next) tail = tail->next;
    quick_sort_list(head, tail);
    return head;
}

//插入排序
ListNode* insertSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p = dummy;
    ListNode* q = head->next;
    ListNode* pre = head;
    while (q != nullptr)
    {
        while (p != q)
        {
            if (p->next->val > q->val) {
                ListNode* back = q->next;
                q->next = p->next;
                p->next = q;
                pre->next = back;
                q = pre;
                break;
            }
            p = p->next;
        }

        pre = q;
        p = dummy; //每次比较完返回
        q = q->next;
    }
    return dummy->next;
}


void print(ListNode* head) {
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* findMidNode(ListNode* head) {
    //这里有陷阱，要fast要先走一步或者两步，要不然两个节点的链表会无法断开
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merger(ListNode* left, ListNode* right) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (left != nullptr && right != nullptr)
    {
        if (left->val < right->val) {
            cur->next = left;
            left = left->next;
        }
        else {
            cur->next = right;
            right = right->next;
        }
        cur = cur->next;
    }
    if (left != nullptr) {
        cur->next = left;
    }
    else {
        cur->next = right;
    }
    return dummy->next;
}

//归并排序
ListNode* merger_sort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) { //递归出口为一个节点，head == nullptr传入的链表为空
        return head;
    }
    //第一步:二分链表，这里返回的midNode是链表中间节点的前一个节点
    ListNode* midNode = findMidNode(head);
    ListNode* rightHead = midNode->next;
    //切断链表
    midNode->next = nullptr;

    //第三步:排序
    //左边排序
    ListNode* left = merger_sort(head);
    //右边排序
    ListNode* right = merger_sort(rightHead);
    //合并
    return merger(left, right);
}

int main() {
    ListNode* head = new ListNode(4);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    ListNode* tail = head;
    print(head);
    ListNode* new_head = merger_sort(head);
    print(new_head);
    // cout << findMidNode(new_head)->val << endl;
    return 0;
}