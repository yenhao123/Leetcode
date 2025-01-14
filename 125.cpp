#include <iostream>
#include <string>
#include <cctype> // For isalnum and tolower
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // convert string into lowercase and remove non-alphanumeric characters
        string formatted_string;
        for(char c : s){
            if(isalnum(c)){
                formatted_string += tolower(c);
            }
        }

        cout << formatted_string << endl;
        // check palindrome
        int string_len = formatted_string.size();
        int left_part_idx, right_part_idx;
        if(string_len % 2 != 0){
            int med_idx = string_len / 2;
            left_part_idx = med_idx - 1;
            right_part_idx = med_idx + 1; 
        }else{
            right_part_idx = string_len / 2;
            left_part_idx = right_part_idx - 1;
        }

        while(right_part_idx < formatted_string.size()){
            if(formatted_string[left_part_idx] != formatted_string[right_part_idx]){
                return false;
            }
            left_part_idx -= 1;
            right_part_idx += 1;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1: Basic palindrome string
    string test1 = "A man, a plan, a canal, Panama";
    cout << "Test 1: " << boolalpha << solution.isPalindrome(test1) << endl;
}