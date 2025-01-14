#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    //inti func
    ListNode(int x) : val(x), next(nullptr) {}
};
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while(cur1 && cur2){
            if(cur1->val <= cur2->val){
                ListNode* tmp = cur1->next;
                cur1->next = cur2;
                cur1 = tmp;
            }else{
                ListNode* tmp = cur2->next;
                cur2->next = cur1;
                cur2 = tmp;
            }
        }
        return list1;
    }
};
*/     

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* result = new ListNode(0);
        ListNode* res_cur = result;
        while(cur1 && cur2){
            if(cur1->val <= cur2->val){
                res_cur->next = cur1;
                res_cur = res_cur->next;
                cur1 = cur1->next;
            }else{
                res_cur->next = cur2;
                res_cur = res_cur->next;
                cur2 = cur2->next;
            }
        }
        while(cur1){
            res_cur->next = cur1;
            res_cur = res_cur->next;
            cur1 = cur1->next;
        }
        while(cur2){
            res_cur->next = cur2;
            res_cur = res_cur->next;
            cur2 = cur2->next;
        }
        res_cur->next = nullptr;
        return result->next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 測試用例
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution solution;

    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    printList(mergedList);  // 輸出: 1 2 3 4 5 6

    return 0;
}