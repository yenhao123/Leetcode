class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            map<int, int> negNumToIdx;
            int absMinNum = INT_MAX, absMinIdx;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < 0) {
                    negNumToIdx.insert({i, nums[i]});
                }
                if (abs(nums[i]) < absMinNum) {
                    absMinNum = abs(nums[i]);
                    absMinIdx = i;
                }
            }
    
            for (auto [num, idx] : negNumToIdx) {
                if (k <= 0) break;
                nums[idx] *= -1;
                k--;
            }
            if (k > 0) nums[absMinIdx] *= -1;
    
            int total = 0;
            for (int i = 0; i < nums.size(); i++) {
                total += nums[i];
                cout << i << ":" << nums[i] << endl;
            }
            return total;
        }
    };