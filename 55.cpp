#include <vector>
#include <iostream>

using namespace std;
/*
//sol1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == 0){
                bool jump_flag = false;
                for(int j = 0; j < i; j++){
                    if(nums[j] > (i - j)){
                        jump_flag = true;
                        continue;
                    }
                }

                if(!jump_flag){
                    cout << i << endl;
                    return false;
                }
            }
        }
        return true;
    }
};
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            reachable = max(reachable, i + nums[i]);
            if(i >= reachable){
                cout << i << endl;
                return false;
            }
        }
        return true;
    }
};

// Test Cases
int main() {
    Solution solution;

    // Test case 1: Can jump to the last index.
    vector<int> testcase1 = {2, 3, 1, 1, 4};
    cout << (solution.canJump(testcase1) ? "True" : "False") << endl;  // Expected output: True

    // Test case 2: Cannot reach the last index.
    vector<int> testcase2 = {3, 2, 1, 0, 4};
    cout << (solution.canJump(testcase2) ? "True" : "False") << endl;  // Expected output: False

    // Test case 3: Single element (already at the last index).
    vector<int> testcase3 = {0};
    cout << (solution.canJump(testcase3) ? "True" : "False") << endl;  // Expected output: True

    // Test case 4: All elements are large enough to jump over zeros.
    vector<int> testcase4 = {5, 0, 0, 0, 0};
    cout << (solution.canJump(testcase4) ? "True" : "False") << endl;  // Expected output: True

    // Test case 5: Only one big jump available at the start.
    vector<int> testcase5 = {4, 0, 0, 0, 0};
    cout << (solution.canJump(testcase5) ? "True" : "False") << endl;  // Expected output: True

    return 0;
}
