class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nNums = nums.size();
        int prev = nums[0], maxValue = nums[0];
        unordered_map<int, int> count;
        count[0] = 1;
        for (int i = 1; i < nNums*2-1; i++) {
            if (count[i-1] < nNums) {
                if (prev+nums[i%nNums] > nums[i%nNums]) {
                    prev = prev + nums[i%nNums];
                    count[i] = count[i-1] + 1;
                } else {
                    prev = nums[i%nNums];
                    count[i] = 1;
                }
                maxValue = max(prev, maxValue);
            } else {
                cout << i << ":" << nums[(i-nNums)%nNums] << endl;
                if (prev+nums[i%nNums]-nums[(i-nNums)%nNums] > nums[i%nNums]) {
                    prev = prev + nums[i%nNums]-nums[(i-nNums)%nNums];
                    count[i] = count[i-1];
                } else {
                    prev = nums[i%nNums];
                    count[i] = 1;
                }
                maxValue = max(prev, maxValue);
            }

            cout << i << ":" << maxValue << "," << prev << endl;
        }

        return maxValue;
    }
};