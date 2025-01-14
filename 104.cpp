#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int max_depth = 1;
        vector<pair<TreeNode*, int>> unvisit;
        unvisit.push_back({root, 1});
        while(!unvisit.empty()){
            auto [cur, cur_depth] = unvisit.back();
            unvisit.pop_back();

            // check leaf or not
            if(cur->left || cur->right){
                if(cur->right)unvisit.push_back({cur->right, cur_depth + 1});
                if(cur->left)unvisit.push_back({cur->left, cur_depth + 1});
            }else{
                if(cur_depth > max_depth){
                    max_depth = cur_depth;
                }
            }
        }
        return max_depth;
    }
};

void testMaxDepth() {
    Solution solution;

    // Test Case 1: 空樹
    TreeNode* root1 = nullptr;
    cout << "Test Case 1: " << solution.maxDepth(root1) << " (Expected: 0)" << endl;

    // Test Case 2: 單節點樹
    TreeNode* root2 = new TreeNode(1);
    cout << "Test Case 2: " << solution.maxDepth(root2) << " (Expected: 1)" << endl;

    // Test Case 3: 完全二元樹
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    cout << "Test Case 3: " << solution.maxDepth(root3) << " (Expected: 3)" << endl;

    // Test Case 4: 不平衡二元樹
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);
    root4->left->left->left = new TreeNode(4);
    cout << "Test Case 4: " << solution.maxDepth(root4) << " (Expected: 4)" << endl;

    // Test Case 5: 樹只有右節點
    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);
    root5->right->right->right = new TreeNode(4);
    cout << "Test Case 5: " << solution.maxDepth(root5) << " (Expected: 4)" << endl;
}

int main() {
    testMaxDepth();
    return 0;
}