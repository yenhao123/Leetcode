#include <iostream>
#include <vector>
using namespace std;

// 請確保以下這個 Solution 類別不做修改
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp_arr(amount + 1, vector<int>(coins.size() + 1, INT_MAX/2));
        for(int i = 0; i < coins.size(); i++){
            dp_arr[0][i] = 0;
        }
        for (int w = 1; w <= amount; w++){
            for (int i = 1; i <= coins.size(); i++){
                // 取
                int comb = INT_MAX/2;
                if(w - coins[i - 1] >= 0){
                    comb = dp_arr[w - coins[i-1]][i-1] + 1;
                }
                dp_arr[w][i] = min(comb, dp_arr[w][i-1]);
                cout << w << "," << i << ":" <<  dp_arr[w][i] << "," << comb << endl;
                //cout << dp_arr[w][i] << endl;
            }
        }
        if(dp_arr[amount][coins.size()] == INT_MAX/2){
            return -1;
        } else {
            return dp_arr[amount][coins.size()];
        }
    }
};

int main() {
    // Test Case 1:
    {
        vector<int> coins = {1, 2, 5};
        int amount = 11;
        Solution sol;
        int result = sol.coinChange(coins, amount);
        cout << "Test Case 1: Expected: 3, Got: " << result << endl;
    }
    /*
    // Test Case 2:
    {
        vector<int> coins = {2};
        int amount = 3;
        Solution sol;
        int result = sol.coinChange(coins, amount);
        cout << "Test Case 2: Expected: -1, Got: " << result << endl;
    }
    
    // Test Case 3:
    {
        vector<int> coins = {1};
        int amount = 0;
        Solution sol;
        int result = sol.coinChange(coins, amount);
        cout << "Test Case 3: Expected: 0, Got: " << result << endl;
    }
    
    // Test Case 4:
    {
        vector<int> coins = {186, 419, 83, 408};
        int amount = 6249;
        Solution sol;
        int result = sol.coinChange(coins, amount);
        cout << "Test Case 4: Expected: 20, Got: " << result << endl;
    }
    */
    return 0;
}
