#include <iostream>
#include <string>
#include <algorithm>  // for reverse
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n_char = min(a.size(), b.size());
        int carry = 0, sum = 0;
        int checked_idx = 0;
        int a_digit, b_digit;
        string output = "";
        while(checked_idx < n_char){
            a_digit = a[a.size() - 1 - checked_idx] - '0';
            b_digit = b[b.size() - 1 - checked_idx] - '0';
            sum = a_digit ^ b_digit ^ carry;
            carry = (a_digit & b_digit) | (a_digit & carry) | (b_digit & carry);
            output += (sum + '0');
            checked_idx += 1;
        }
        while(checked_idx < a.size()){
            a_digit = a[a.size() - 1 - checked_idx] - '0';
            sum = a_digit ^ carry;
            carry = (a_digit & carry);
            output += (sum + '0');
            checked_idx += 1;
        }
        while(checked_idx < b.size()){
            b_digit = b[b.size() - 1 - checked_idx] - '0';
            sum = b_digit ^ carry;
            carry = (b_digit & carry);
            output += (sum + '0');
            checked_idx += 1;
        }
        if(carry != 0){
            output += "1";
        }
        reverse(output.begin(), output.end());
        return output;
    }
};

int main() {
    Solution solution;
    string a = "1101";  // Example binary string
    string b = "1011";  // Another example binary string

    string result = solution.addBinary(a, b);
    cout << "Sum: " << result << endl;  // Expected Output: "11000"
    return 0;
}