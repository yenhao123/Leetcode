#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n_nums = nums.size();
        int left = 0;
        int right = n_nums - 1;
        int med = (left + right) / 2;
        while(med < right && med > left){
            if(target == nums[med]){
                return med;
            }else if(target > nums[med]){
                left = med;
                med = (left + right) / 2;
            }else{
                right = med;
                med = (left + right) / 2;
            }
            cout << med << endl;
        }
        if(target > nums[right])return right + 1;
        else{
            if(target > nums[left]) return left + 1;
            else return left;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 6};
    cout << "Test Case 1: " << sol.searchInsert(nums1, 5) << " (expect: 2)" << endl;

    vector<int> nums2 = {1, 3, 5, 6};
    cout << "Test Case 2: " << sol.searchInsert(nums2, 2) << " (expect: 1)" << endl;

    vector<int> nums3 = {1, 3, 5, 6};
    cout << "Test Case 3: " << sol.searchInsert(nums3, 7) << " (expect: 4)" << endl;

    vector<int> nums4 = {1, 3, 5, 6};
    cout << "Test Case 4: " << sol.searchInsert(nums4, 0) << " (expect: 0)" << endl;

    return 0;
}