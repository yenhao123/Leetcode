#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort
using namespace std;


int binary_search_right(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] <= target) {
            left = mid + 1;
        }
    }
    return left;
}
int main() {
    vector<int> nums = {1,3,4,4,4,7,8};
    cout << binary_search_right(nums, 3)  << endl; // 2 <- 找到，回傳最右邊的 index + 1
    cout << binary_search_right(nums, 4)  << endl; // 5 <- 找到，回傳最右邊的 index + 1
    cout << binary_search_right(nums, 5)  << endl; // 5 <- 找不到，但回傳 > 他的裡面，最小的元素 index
    cout << binary_search_right(nums, 11) << endl; // 7 <- 同上，雖超出最大 index 範圍，卻是合理的
}