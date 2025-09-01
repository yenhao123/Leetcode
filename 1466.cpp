class Solution {
    int res = 0;
    void dfs(int i, vector<vector<int>>& undgraph, vector<unordered_set<int>>& graph, vector<bool>& visited) {
        visited[i] = true;
        for (auto nei : undgraph[i]) {
            if (!visited[nei]) {
                if (graph[i].find(nei) != graph[i].end()) res++;
                dfs(nei, undgraph, graph, visited);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> undgraph(n);
        vector<unordered_set<int>> graph(n);
        for (auto connection : connections) {
            int from = connection[0], to = connection[1];
            undgraph[from].push_back(to);
            undgraph[to].push_back(from);
            graph[from].insert(to);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i, undgraph, graph, visited);
        }
        return res;
    }
};