#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n_cites = citations.size();
        // sorted
        sort(citations.begin(), citations.end());
        
        // get h_index, 5 papers which cite>=2 / cite=2 -> hindex = 4, not 2
        int n_papers = 0;
        for(int i = n_cites - 1; i >= 0; i--){
            n_papers += 1;
            if(n_papers == citations[i]){
                return n_papers;
            }
            if(n_papers > citations[i]){
                return n_papers - 1;
            }
        }
        return n_papers;
    }
};

// Test Cases
int main() {
    Solution solution;

    // Test case 1: Basic example
    vector<int> citations1 = {3, 0, 6, 1, 5};
    cout << "H-index (Test Case 1): " << solution.hIndex(citations1) << endl;  // Expected output: 3

    // Test case 2: No citations
    vector<int> citations2 = {0, 0, 0, 0};
    cout << "H-index (Test Case 2): " << solution.hIndex(citations2) << endl;  // Expected output: 0

    // Test case 3: All papers highly cited
    vector<int> citations3 = {10, 8, 5, 4, 3};
    cout << "H-index (Test Case 3): " << solution.hIndex(citations3) << endl;  // Expected output: 4

    // Test case 4: Single paper
    vector<int> citations4 = {10};
    cout << "H-index (Test Case 4): " << solution.hIndex(citations4) << endl;  // Expected output: 1

    // Test case 5: Edge case with increasing citations
    vector<int> citations5 = {1, 2, 3, 4, 5};
    cout << "H-index (Test Case 5): " << solution.hIndex(citations5) << endl;  // Expected output: 3

    // Test case 1: Basic example
    vector<int> citations6 = {4, 0, 6, 1, 5};
    cout << "H-index (Test Case 6): " << solution.hIndex(citations6) << endl;  // Expected output: 3

    return 0;
}
