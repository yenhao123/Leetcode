class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            vector<int> schedule (days+1, 0);
            for (auto meeting : meetings) {
                schedule[meeting[0]-1] += 1;
                schedule[meeting[1]] -= 1;
            }
    
            int res = (schedule[0] == 0) ? 1 : 0;
            for (int i = 1; i < days; i++) {
                schedule[i] += schedule[i-1];
                if (schedule[i] == 0) res += 1;
            }
            return res;
        }
    };