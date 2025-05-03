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
        int amountOfTime(TreeNode* root, int start) {
            unordered_map<int, vector<TreeNode*>> graph;
            // build graph
            buildGraph(root, nullptr, graph);
    
            for (auto [key, value] : graph) {
                for (auto i : graph[key]) {
                    cout << key << ":" << i->val << endl;
                }
            }
            // level_order traversal

            queue<int> q;
            q.push(start);
            unordered_set<int> visited;
            int nMins = -1;
            while (!q.empty()) {
                int levelSize = q.size();
                for (int i = 0; i < levelSize; i++) {
                    int key = q.front();
                    q.pop();
                    visited.insert(key);

                    for (auto neighbor : graph[key]) {
                        if (visited.find(neighbor->val) == visited.end()) q.push(neighbor->val);
                    }
                }
                nMins += 1;
            }

            return nMins;
        }
    
        void buildGraph(TreeNode* root, TreeNode* parent, unordered_map<int, vector<TreeNode*>>& graph) {
            if (!root) return;
            if (parent) graph[root->val].push_back(parent);
            if (root->left) graph[root->val].push_back(root->left);
            if (root->right) graph[root->val].push_back(root->right);
            buildGraph(root->left, root, graph);
            buildGraph(root->right, root, graph);
        }
    };