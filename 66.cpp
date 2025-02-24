#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int least_digit = digits[digits.size()-1];
        if((least_digit + 1) < 10){
            digits[digits.size() - 1] = least_digit + 1;
            return digits;
        }

        int carry_idx = digits.size() - 1;
        while(carry_idx >= 0){
            int digit = digits[carry_idx];
            if((digit + 1) < 10){
                digits[carry_idx] = (digit + 1);
                return digits;
            }else{
                digits[carry_idx] = 0;
                carry_idx -= 1;
            }
        }
        vector<int> results = {1};
        results.insert(results.end(), digits.begin(), digits.end());
        return results;
        
    }
};