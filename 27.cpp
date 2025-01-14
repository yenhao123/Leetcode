#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int check_pt = 0, swap_pt = 1;
        // if no element can be check break, else check
        while(check_pt < nums.size()){
            // if value of checked element is "val", else swap
            if(nums[check_pt] == val){
                // if no element can be swap break, else swap
                if(swap_pt >= nums.size()){
                    break;
                }
                int tmp = nums[check_pt];
                nums[check_pt] = nums[swap_pt];
                nums[swap_pt] = tmp;
                swap_pt += 1;
            }else{
                check_pt += 1;
                if(swap_pt <= check_pt){
                    swap_pt = check_pt + 1;
                }
            }
            cout << "Updated nums: ";
            for (int i = 0; i < nums.size(); ++i) {
                cout << nums[i] << " ";
            }
            cout << ", Check pointer: " << check_pt << ", Push Pointer:" << swap_pt;
            cout << endl;
        }
        return check_pt;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2};
    int val = 3;
    
    // call function
    int new_length = solution.removeElement(nums, val);
    
    // output results
    cout << "New length: " << new_length << endl;
    cout << "Updated nums: ";
    for (int i = 0; i < new_length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}