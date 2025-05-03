#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    vector<int> lis_hist;

public:
    int lengthOfLIS(vector<int>& nums) {
        lis_hist = vector<int>(nums.size(), -1);
        int max_num = INT_MIN;
        return LIS(nums, 0, max_num);
    }

    int LIS(vector<int>& nums, int idx, int max_num){
        if(idx == nums.size()){
            return 0;
        }
        //cout << idx << endl;
        if(lis_hist[idx] != -1){
            cout << lis_hist[idx] << endl;
            return lis_hist[idx];
        }
        
        int count;
        if(nums[idx] <= max_num){
            count = LIS(nums, idx + 1, max_num);
        }else{
            // 不取 or 取
            int count1 = LIS(nums, idx + 1, max_num);
            int count2 = LIS(nums, idx + 1, nums[idx]) + 1;
            count = max(count1, count2);
        }
        lis_hist[idx] = count;
        return count;
    }
};

// 測試函數
void test() {
    Solution solution;
/*
    vector<vector<int>> testcases = {
        {10, 9, 2, 5, 3, 7, 101, 18},  // 答案: 4 (2,3,7,101)
        {0, 1, 0, 3, 2, 3},            // 答案: 4 (0,1,2,3)
        {7, 7, 7, 7, 7, 7, 7},        // 答案: 1 (7)
        {1, 3, 6, 7, 9, 4, 10, 5, 6}, // 答案: 6 (1,3,4,5,6,10)
        {5, 8, 7, 1, 9},              // 答案: 3 (5,7,9)
        {1},                          // 答案: 1 (1)
        {4, 10, 4, 3, 8, 9},          // 答案: 3 (4,8,9)
        {1, 2, 3, 4, 5},              // 答案: 5 (1,2,3,4,5)
        {5, 4, 3, 2, 1}               // 答案: 1 (5 or any single number)
    };
*/
    vector<vector<int>> testcases = {
        {10, 9, 2, 5, 3, 7, 101, 18},  // 答案: 4 (2,3,7,101)
    };

    for (int i = 0; i < testcases.size(); ++i) {
        int result = solution.lengthOfLIS(testcases[i]);
        cout << "Test case " << i + 1 << ": " << result << endl;
    }
}

// 主函數
int main() {
    test();
    return 0;
}
