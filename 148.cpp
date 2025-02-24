#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// buble sort
/*
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n_ele = cout_ele(head);
        for(int i = 0; i< n_ele; i++){
            head = sort_onestep(head);
        }

        return head;
    }

    int cout_ele(ListNode* head){
        int n_ele = 0;
        ListNode* cur = head;
        while(cur){
            n_ele += 1;
            cur = cur->next;
        }
        return n_ele;
    }

    ListNode* sort_onestep(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur) {
            // swap
            if (cur->next && cur->val > cur->next->val) {  // 避免 cur->next 為 nullptr
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                tmp->next = cur;
                if(prev) prev->next = tmp;
                prev = tmp;
                if(cur == head) head = tmp;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};
*/

// merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;

        // split
        ListNode* slow = head, *fast = head, *prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        //merge
        head = merge(left, right);
        return head;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode new_seq(0);
        ListNode* tail = &new_seq;

        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        tail->next = left ? left : right;
        
        return new_seq.next;
    }
};

// **工具函式：列印鏈表**
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// **測試函式**
void test() {
    Solution sol;

    // 測試 1: 一般情況
    ListNode* test1 = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    cout << "Before sorting: ";
    printList(test1);
    test1 = sol.sortList(test1);
    cout << "After sorting: ";
    printList(test1);
    
    // 測試 2: 已排序
    ListNode* test2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    cout << "\nBefore sorting: ";
    printList(test2);
    test2 = sol.sortList(test2);
    cout << "After sorting: ";
    printList(test2);
    
    // 測試 3: 逆序排序
    ListNode* test3 = new ListNode(5, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(1)))));
    cout << "\nBefore sorting: ";
    printList(test3);
    test3 = sol.sortList(test3);
    cout << "After sorting: ";
    printList(test3);
    
    // 測試 4: 單節點
    ListNode* test4 = new ListNode(1);
    cout << "\nBefore sorting: ";
    printList(test4);
    test4 = sol.sortList(test4);
    cout << "After sorting: ";
    printList(test4);
    
    // 測試 5: 空鏈表
    ListNode* test5 = nullptr;
    cout << "\nBefore sorting: ";
    printList(test5);
    test5 = sol.sortList(test5);
    cout << "After sorting: ";
    printList(test5);
}

int main() {
    test();
    return 0;
}
