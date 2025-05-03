class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<int, vector<int>> adjlist;
        vector<int> indegAll(recipes.size());
        for (int i = 0; i < recipes.size(); i++) {
            for (int j = 0; j < ingredients.size(); j++) {
                for (int k = 0; k < ingredients[j].size(); k++) {
                    if (recipes[i] == ingredients[j][k]) {
                        adjlist[i].push_back(j);
                        indegAll[j] += 1;
                        break;
                    }
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < recipes.size(); i++) {
            if(indegAll[i] == 0) q.push(i);
        }

        unordered_set<string> suppliesMap;
        for (auto s : supplies) {
            suppliesMap.insert(s);
        }

        vector<string> res;
        while(!q.empty()) {
            int nodeIdx = q.front();
            q.pop();
            
            // check supply & update supply
            bool canMake = true;
            for (auto ingredient : ingredients[nodeIdx]) {
                if (suppliesMap.find(ingredient) == suppliesMap.end()) {
                    canMake = false;
                    break;
                }
            }
            if (canMake) {
                suppliesMap.insert(recipes[nodeIdx]);
                res.push_back(recipes[nodeIdx]);
            }

            // update indegree
            for(int neighIdx : adjlist[nodeIdx]) {
                indegAll[neighIdx] -= 1;
                if(indegAll[neighIdx] == 0) q.push(neighIdx);
            }
        }

        return res;
    }
};