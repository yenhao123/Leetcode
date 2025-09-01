class Solution {
    bool res = false;
    void backtracking(vector<int>& allpower, vector<int>& comb, int cur, int sum, int target) {
        if (cur > allpower.size()) return;
        if (res) return;
        if (sum == target) res = true;

        for (int i = cur; i < allpower.size(); i++) {
            comb.push_back(allpower[i]);
            backtracking(allpower, comb, i+1, sum+allpower[i], target);
            comb.pop_back();
        }
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int> allpower;
        int cur = 1;
        while (cur <= n) {
            allpower.push_back(cur);
            cur *= 3;
        }
        vector<int> comb;
        backtracking(allpower, comb, 0, 0, n);
        return res;
    }
};