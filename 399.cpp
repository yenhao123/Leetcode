class Solution {
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited, string node, string target, double total) {
        if (node == target) return total;
        visited.insert(node);

        double resAll = -1.0;
        for (auto [nei, cost] : graph[node]) {
            if (!visited.count(nei)) {
                double res = dfs(graph, visited, nei, target, total * cost);
                resAll = max(resAll, res);
            }
        }

        return resAll;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0], to = equations[i][1];
            double value = values[i];
            graph[from].push_back({to, value});
            graph[to].push_back({from, 1 / value});
        }

        vector<double> res;
        for (auto query : queries) {
            string from = query[0], to = query[1];
            if (!graph.count(to) || !graph.count(from)) {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            res.push_back(dfs(graph, visited, from, to, 1.0));
        }
        return res;
    }
};