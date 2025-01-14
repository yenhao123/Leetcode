#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hist_num;

        while(n != 1){
            // insert element
            hist_num.insert(n);
            
            // get sum
            int sum = 0;
            while(n > 0){
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            n = sum;
            // determine sum are not occured
            if(hist_num.find(sum) != hist_num.end()){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    cout << "Test Case 1: " << (solution.isHappy(19) ? "true" : "false") << endl;  // true
    cout << "Test Case 2: " << (solution.isHappy(2) ? "true" : "false") << endl;   // false
    cout << "Test Case 3: " << (solution.isHappy(1) ? "true" : "false") << endl;   // true
    cout << "Test Case 4: " << (solution.isHappy(7) ? "true" : "false") << endl;   // true
    cout << "Test Case 5: " << (solution.isHappy(116) ? "true" : "false") << endl; // false
    cout << "Test Case 6: " << (solution.isHappy(1000000) ? "true" : "false") << endl; // true

    return 0;
}
