#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        cout << nums.size() << endl;

        vector<int> res(nums.size(), abs(nums[0]));
        for(int i = 1; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j >= 0; j--){
                sum += nums[j];
                res[i] = max(res[i], abs(sum));
            }
            res[i] = max(res[i], res[i-1]);
            cout << i << ":" << res[i] << endl;
        }
        return res[nums.size() - 1];
    }
};

// 測試函數
void runTest(vector<int> nums, int expected) {
    Solution solution;
    int result = solution.maxAbsoluteSum(nums);
    cout << "Input: ";
    for(int num : nums) cout << num << " ";
    cout << "\nOutput: " << result << " (Expected: " << expected << ")";
    cout << (result == expected ? " ✅" : " ❌") << endl;
}

// 主函數
int main() {
    vector<pair<vector<int>, int>> testcases = {
        {{1, -3, 2, 3, -4}, 5},    // 最大子數列為 [2,3] 或 [-3,2,3]，絕對值最大為 5
        {{2, -5, 1, -4, 3, -2}, 8}, // 最大子數列為 [2,-5,1,-4,3] 或 [-5,1,-4,3,-2]，絕對值最大為 6

    };

    for (auto& testcase : testcases) {
        runTest(testcase.first, testcase.second);
    }

    ifstream file("large_testcase.txt"); // 讀取檔案
    vector<int> nums;
    int num;
    
    while (file >> num) {
        nums.push_back(num);
    }
    file.close();

    // 測試你的 maxAbsoluteSum()
    Solution solution;
    int result = solution.maxAbsoluteSum(nums);
    
    cout << "Max Absolute Sum: " << result << endl;
    return 0;
}
