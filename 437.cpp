class Solution {
    public:
        void dfs(TreeNode* node,vector<int> path,int targetSum,int& count){
            //終止條件
            if(!node){
                return;
            }
            path.push_back(node->val);
    
            long sum = 0;
            for (int i = path.size() - 1; i >= 0; i--) {
                sum += path[i];
                if (sum == targetSum) count++;
            }
    
            dfs(node->left,path,targetSum,count);
            dfs(node->right,path,targetSum,count);
    
            path.pop_back();
        }
        int pathSum(TreeNode* root, int targetSum) {
            int count = 0;
            TreeNode* ptr = root;
            vector<int> path;
    
            dfs(root,path,targetSum,count);
            return count;
        }
    };