#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // 只有一個節點，必然是回文

        ListNode* cur = head;
        int n_list = 0;
        
        // 計算鏈表長度
        while (cur) {
            n_list++;
            cur = cur->next;
        }

        int seg1_end = (n_list / 2) - 1;
        int seg2_start = (n_list % 2 == 0) ? (n_list / 2) : (n_list / 2 + 1);

        stack<int> s;
        int cur_idx = 0;
        cur = head;

        while (cur) {
            if (cur_idx <= seg1_end) {
                s.push(cur->val);
            } else if (cur_idx >= seg2_start) {
                if (s.empty()) return false; // 檢查 stack 是否為空，避免崩潰
                int val = s.top();
                s.pop();
                if (val != cur->val) return false;
            }
            cur = cur->next;
            cur_idx++;
        }

        return true;
    }
};

// 測試函式
void test() {
    Solution solution;

    ListNode* test1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    ListNode* test2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
    ListNode* test3 = new ListNode(1, new ListNode(2));
    ListNode* test4 = new ListNode(1);

    cout << "Test case 1: " << solution.isPalindrome(test1) << endl; // 1 (true)
    cout << "Test case 2: " << solution.isPalindrome(test2) << endl; // 1 (true)
    cout << "Test case 3: " << solution.isPalindrome(test3) << endl; // 0 (false)
    cout << "Test case 4: " << solution.isPalindrome(test4) << endl; // 1 (true)
}

int main() {
    test();
    return 0;
}
