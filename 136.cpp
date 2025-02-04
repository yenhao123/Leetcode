#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> non_single;
        unordered_map<int, int> umap;
        for(int num : nums){
            if(umap.find(num) == umap.end()){
                non_single.push_back(num);
                umap.insert({num, non_single.size()-1});
            }else{
                int non_single_idx = umap[num];
                non_single[non_single_idx] = non_single.back();
                umap[non_single.back()] = non_single_idx;
                non_single.pop_back();
                umap.erase(num);
            }
        }

        if(non_single.size() != 1)
            throw runtime_error("-1");
        
        return non_single[0];
    }
};

// 測試函式
void test() {
    Solution sol;
    
    vector<vector<int>> test_cases = {
        {2, 2, 1},             // Output: 1
        {4, 1, 2, 1, 2},       // Output: 4
        {1},                   // Output: 1 (單一元素)
        {-1, -1, -2},          // Output: -2 (負數)
        {0, 1, 0},             // Output: 1
        {5, 5, 6, 6, 7},       // Output: 7
        {100, 200, 100},       // Output: 200
        {9, 9, 8, 8, 7, 7, 3}, // Output: 3
        {1, 3, 1, -1, 3}, //output -1
    };
    
    for (const auto& nums : test_cases) {
        try {
            cout << "Input: ";
            for (int num : nums) cout << num << " ";
            cout << "\nOutput: " << sol.singleNumber(const_cast<vector<int>&>(nums)) << "\n\n";
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n\n";
        }
    }
}

int main() {
    test();
    return 0;
}
