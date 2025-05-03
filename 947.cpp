class Solution {
public:
    int dfs(vector<vector<int>>& stones, vector<bool>& visited, int stoneIdx) {
        visited[stoneIdx] = true;
        int canRemoveStone = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] && (stones[stoneIdx][0] == stones[i][0] || stones[stoneIdx][1] == stones[i][1])) {
                canRemoveStone += (dfs(stones, visited, i) + 1);
            }
        }

        return canRemoveStone;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int nRemoveStones = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int canRemoveStone = dfs(stones, visited, i);
            nRemoveStones += canRemoveStone;
        }
        return nRemoveStones;
    }
};