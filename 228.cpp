#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        if(nums.empty()) return output;

        int inv_start = nums[0], inv_end = nums[0];

        for(int i = 1; i < nums.size(); i++){
            // if gap exists, save interval
            if(inv_end + 1 != nums[i]){
                string o;
                if(inv_start != inv_end){
                    o = to_string(inv_start)+ "->" + to_string(inv_end);
                }else{
                    o = to_string(inv_start);
                }
                output.push_back(o);
                inv_start = nums[i];
                inv_end = nums[i];
            }else{
                inv_end = nums[i];
            }
        }

        // save last interval
        string o;
        if(inv_start != inv_end){
            o = to_string(inv_start)+ "->" + to_string(inv_end);
        }else{
            o = to_string(inv_start);
        }
        output.push_back(o);
        return output;
    }
};

void runTests() {
    Solution solution;
    vector<vector<int>> testCases = {
        {0, 1, 2, 4, 5, 7},        // [0->2, 4->5, 7]
        {0, 2, 3, 4, 6, 8, 9},     // [0, 2->4, 6, 8->9]
        {},                        // []
        {1},                       // [1]
        {-10, -9, -8, 5, 6, 10},   // [-10->-8, 5->6, 10]
        {1, 3, 5, 7}               // [1, 3, 5, 7]
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector<string> result = solution.summaryRanges(testCases[i]);
        cout << "Test Case " << i + 1 << ": ";
        for (const auto& range : result) {
            cout << range << " ";
        }
        cout << endl;
    }
}

int main() {
    runTests();  // 執行測試
    return 0;
}