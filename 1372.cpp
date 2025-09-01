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
    int countZigZag(TreeNode* root) {
        TreeNode* tmp = root;
        int lres = -1;
        bool isLeft = true;
        while (tmp) {
            if (isLeft) {
                tmp = tmp->left;
                isLeft = false;
            } else {
                tmp = tmp->right;
                isLeft = true;
            }
            lres++;
        }

        tmp = root;
        int rres = -1;
        bool isRight = true;
        while (tmp) {
            if (isRight) {
                tmp = tmp->right;
                isRight = false;
            } else {
                tmp = tmp->left;
                isRight = true;
            }
            rres++;
        } 

        return max(lres, rres);
    }
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;

        int res = countZigZag(root);

        int lRes = longestZigZag(root->left);
        int rRes = longestZigZag(root->right);
        
        return max({res, lRes, rRes});
    }
};