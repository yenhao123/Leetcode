#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    int left_side;
    int right_side;
public:
    bool is_critic_point(ListNode* node) {
        right_side = (node->val > node->next->val) ? 1 : (node->val < node->next->val ? -1 : 0);
        return (left_side != right_side) && (left_side != 0) && (right_side != 0);
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next->next) return {-1, -1};
        ListNode* cur = head;
        vector<int> res = {INT_MAX, INT_MIN};

        // get left side
        left_side = (cur->val > cur->next->val) ? 1 : (cur->val < cur->next->val ? -1 : 0);
        cur = cur->next;

        // check each critical points
        int idx = 0;
        int start_critic_p = -1, prev_critic_p = -1;
        while(cur->next) {
            if(is_critic_point(cur)) {
                if(prev_critic_p != -1) {
                    int dist = idx - prev_critic_p;
                    res[0] = min(dist, res[0]);
                } else {
                    start_critic_p = idx;
                }
                prev_critic_p = idx;
            }

            // update params
            cur = cur->next;
            idx += 1;
            left_side = right_side;
        }

        // get max_dist and check zero critical point case
        res[1] = prev_critic_p - start_critic_p;
        if(res[0] == INT_MAX) {
            res[0] = -1; 
            res[1] = -1;
        }

        return res;
    }
};

/*

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next->next) return {-1, -1};
        ListNode* cur = head;
        vector<int> res = {INT_MAX, INT_MIN};
        vector<int> curve(2);
        curve[0] = (cur->val > cur->next->val) ? 1 : (cur->val < cur->next->val ? -1 : 0);
        cur = cur->next;
        curve[1] = (cur->val > cur->next->val) ? 1 : (cur->val < cur->next->val ? -1 : 0);

        int idx = 1;
        int prev_critic_p = -1;
        if(curve[0] != curve[1] && curve[0] != 0 && curve[1] != 0) {;
            res[1] = idx;
            prev_critic_p = idx;
        }
        cur = cur->next;
        idx += 1;

        while(cur->next) {
            // update curve situ
            curve[0] = curve[1];
            curve[1] = (cur->val > cur->next->val) ? 1 : (cur->val < cur->next->val ? -1 : 0);


            // check critical point
            if(curve[0] != curve[1] && curve[0] != 0 && curve[1] != 0) {
                if(prev_critic_p != -1) {
                    int dist = idx - prev_critic_p;
                    res[0] = min(dist, res[0]);
                } else 
                    res[1] = idx;
                prev_critic_p = idx;
            }

            // update params
            cur = cur->next;
            idx += 1;
        }

        res[1] = prev_critic_p - res[1];
        if(res[0] == INT_MAX) {
            res[0] = -1; 
            res[1] = -1;
        }

        return res;
    }
};
*/