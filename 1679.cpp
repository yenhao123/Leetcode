class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
            unordered_map<int, int> counters;
            for (int num : nums) {
                counters[num]++;
            }
    
            int res = 0;
            for (int num : nums) {
                int x = k - num;
                if (counters.find(x) != counters.end() && counters[x] > 0) {
                    counters[x]--;
                    if (counters[num] > 0) {
                        counters[num]--;
                        res++;
                    } else {
                        counters[x]++;
                    }
                }
    
            }
    
            return res;
        }
    };