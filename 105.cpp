#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // inorder order (key : idx)
        unordered_map<int, int> umap;
        for(int i = 0; i < inorder.size(); i++){
            umap[inorder[i]] = i;
        }
        
        int preorder_index = 0;
        TreeNode* root = construct(preorder, umap, preorder_index, 0, inorder.size()-1);
        return root;
    }
private:
    TreeNode* construct(vector<int>& preorder, unordered_map<int, int>& inorder_map, int& preorder_index, int inorder_start, int inorder_end) {
        // base case
        if(inorder_start > inorder_end)return nullptr;

        // recursive case
        TreeNode* new_node = new TreeNode(preorder[preorder_index]);
        int inorder_index = inorder_map[preorder[preorder_index]];
        preorder_index += 1;
        new_node->left = construct(preorder, inorder_map, preorder_index, inorder_start, inorder_index-1);
        new_node->right = construct(preorder, inorder_map, preorder_index, inorder_index+1, inorder_end);
        return new_node;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution solution;

    // Example 1: Balanced Tree
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};

    TreeNode* root1 = solution.buildTree(preorder1, inorder1);
    cout << "Inorder traversal of constructed tree (Example 1): ";
    printInorder(root1);
    cout << endl;

    // Example 2: Left-Skewed Tree
    vector<int> preorder2 = {1, 2, 3, 4, 5};
    vector<int> inorder2 = {5, 4, 3, 2, 1};

    TreeNode* root2 = solution.buildTree(preorder2, inorder2);
    cout << "Inorder traversal of constructed tree (Example 2): ";
    printInorder(root2);
    cout << endl;

    // Example 3: Right-Skewed Tree
    vector<int> preorder3 = {1, 2, 3, 4, 5};
    vector<int> inorder3 = {1, 2, 3, 4, 5};

    TreeNode* root3 = solution.buildTree(preorder3, inorder3);
    cout << "Inorder traversal of constructed tree (Example 3): ";
    printInorder(root3);
    cout << endl;

    return 0;
}
