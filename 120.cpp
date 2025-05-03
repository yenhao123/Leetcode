#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // initialization
        vector<vector<int>> dp(triangle.size());
        dp[0].push_back(triangle[0][0]);
        for(int row = 1; row < triangle.size(); row++){
            dp[row].push_back(dp[row-1][0] + triangle[row][0]);
        }
        
        // update dp
        for(int row = 1; row < triangle.size(); row++) {
            for(int col = 1; col < triangle[row].size(); col++) {
                int leftParent = dp[row-1][col-1] + triangle[row][col];
                int rightParent = col < dp[row-1].size() ? dp[row-1][col] + triangle[row][col] : INT_MAX;
                dp[row].push_back(min(leftParent, rightParent));
                cout << row << "," << col << ":" << dp[row][col] << endl;
            }
        }

        // get minimum
        int res = INT_MAX, lastRow = dp.size() - 1;
        for(int col = 0; col < dp[lastRow].size(); col++){
            res = min(res, dp[lastRow][col]);
        }

        return res;
    }
};