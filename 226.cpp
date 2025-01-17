#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* new_tree = new TreeNode(root->val);
        TreeNode* new_tree_ptr = new_tree;

        // record level order for the old tree 
        vector<TreeNode*> queue;
        // record reverse level order for the new tree
        vector<TreeNode*> new_tree_queue;
        int queue_idx = 0;
        int new_tree_queue_idx = 0;
        queue.push_back(root);
        new_tree_queue.push_back(new_tree_ptr);
        while(queue_idx < queue.size()){
            // get current node before inverted
            TreeNode* cur = queue[queue_idx++];
            // get current node after inverted
            TreeNode* new_tree_ptr = new_tree_queue[new_tree_queue_idx++];

            if(cur->left){
                new_tree_ptr->right = new TreeNode(cur->left->val);
                queue.push_back(cur->left);
                new_tree_queue.push_back(new_tree_ptr->right);
            }
            if(cur->right){
                new_tree_ptr->left = new TreeNode(cur->right->val);
                queue.push_back(cur->right);
                new_tree_queue.push_back(new_tree_ptr->left);
            }
        }
        
        return new_tree;
    }
};

// Utility function to print a tree in level-order
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Test Cases
int main() {
    Solution solution;

    // Test Case 1: Empty Tree
    TreeNode* root1 = nullptr;
    TreeNode* inverted1 = solution.invertTree(root1);
    cout << "Test Case 1 - Inverted Tree: ";
    printLevelOrder(inverted1); // Output: "Empty tree"

    // Test Case 2: Single Node Tree
    TreeNode* root2 = new TreeNode(1);
    TreeNode* inverted2 = solution.invertTree(root2);
    cout << "Test Case 2 - Inverted Tree: ";
    printLevelOrder(inverted2); // Output: "1"

    // Test Case 3: Simple Tree
    TreeNode* root3 = new TreeNode(4);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(7);
    TreeNode* inverted3 = solution.invertTree(root3);
    cout << "Test Case 3 - Inverted Tree: ";
    printLevelOrder(inverted3); // Output: "4 7 2"

    // Test Case 4: Complex Tree
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    root4->right->left = new TreeNode(6);
    root4->right->right = new TreeNode(7);

    TreeNode* inverted4 = solution.invertTree(root4);
    cout << "Test Case 4 - Inverted Tree: ";
    printLevelOrder(inverted4); // Output: "1 3 2 7 6 5 4"

    return 0;
}
