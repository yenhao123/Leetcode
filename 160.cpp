#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node_a = headA, * node_b = headB;
        while(node_a){
            node_b = headB;
            while(node_b){
                if(node_a == node_b) return node_a;
                node_b = node_b->next;
            }
            node_a = node_a->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* node_a = headA, * node_b = headB;
        unordered_set<ListNode*> uset;

        while(node_a){
            uset.insert(node_a);
            node_a = node_a->next;
        }
        while(node_b){
            if(uset.find(node_b) != uset.end())return node_b;
            node_b = node_b->next;
        }
        return nullptr;
    }
};