#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Iteration version
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // generate old/new node map
        unordered_map<Node*, Node*> umap; 
        Node* cur = head;
        while(cur){
            Node* n = new Node(cur->val);
            umap[cur] = n;
            cur = cur->next;
        }
        
        // handle next & random
        for(auto &[old_node, new_node] : umap){
            if(!old_node->next){
                new_node->next = NULL;
            }else{
                new_node->next = umap[old_node->next];
            }
            if(!old_node->random){
                new_node->random = NULL;
            }else{
                new_node->random = umap[old_node->random];
            }
        }

        return umap[head];
    }
};

void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << "Node value: " << cur->val;
        if (cur->random) {
            cout << ", Random points to: " << cur->random->val;
        } else {
            cout << ", Random is null";
        }
        cout << endl;
        cur = cur->next;
    }
}

int main() {
    // 創建測試鏈表
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    node1->random = node3; // 節點 1 的 random 指向節點 3
    node2->random = node1; // 節點 2 的 random 指向節點 1
    node3->random = node2; // 節點 3 的 random 指向節點 2

    cout << "Original list:" << endl;
    printList(node1);

    // 複製鏈表
    Solution solution;
    Node* copied_head = solution.copyRandomList(node1);

    cout << "\nCopied list:" << endl;
    printList(copied_head);

    return 0;
}