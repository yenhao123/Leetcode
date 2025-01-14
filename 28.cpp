#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // get lps
        int lps[needle.size()];
        lps[0] = 0;
        for(int i = 1; i < needle.size(); i++){
            int j = lps[i-1];
            while(1){
                if(needle[i] == needle[j]){
                    lps[i] = j + 1;
                    break;
                }else{
                    if(j != 0){
                        j = lps[j-1];
                    }else{
                        lps[i] = 0;
                        break;
                    }
                }
            }
        }

        // get matched idx
        int haystack_pt = 0, needle_pt = 0;
        while(haystack_pt < haystack.size()){
            if(haystack[haystack_pt] == needle[needle_pt]){
                haystack_pt += 1;
                needle_pt += 1;
            }else{
                if(needle_pt != 0){
                    needle_pt = lps[needle_pt-1];
                }else{
                    haystack_pt += 1;
                }
            }
            if(needle_pt == needle.size()){
                return haystack_pt - needle.size();
            }
        }
        return -1;
    }
};

// 測試案例
int main() {
    Solution solution;

    // 測試案例 1
    string haystack1 = "hello";
    string needle1 = "ll";
    int result1 = solution.strStr(haystack1, needle1);
    cout << "Test Case 1:" << endl;
    cout << "Haystack: \"" << haystack1 << "\", Needle: \"" << needle1 << "\"" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Actual Output: " << result1 << endl << endl;

    // 測試案例 2
    string haystack2 = "aaaaa";
    string needle2 = "bba";
    int result2 = solution.strStr(haystack2, needle2);
    cout << "Test Case 2:" << endl;
    cout << "Haystack: \"" << haystack2 << "\", Needle: \"" << needle2 << "\"" << endl;
    cout << "Expected Output: -1" << endl;
    cout << "Actual Output: " << result2 << endl << endl;

    // 測試案例 3
    string haystack3 = "abcdabcabcabcd";
    string needle3 = "abcabcd";
    int result3 = solution.strStr(haystack3, needle3);
    cout << "Test Case 3:" << endl;
    cout << "Haystack: \"" << haystack3 << "\", Needle: \"" << needle3 << "\"" << endl;
    cout << "Expected Output: 6" << endl;
    cout << "Actual Output: " << result3 << endl << endl;

    // 測試案例 4
    string haystack4 = "ababcababa";
    string needle4 = "ababa";
    int result4 = solution.strStr(haystack4, needle4);
    cout << "Test Case 4:" << endl;
    cout << "Haystack: \"" << haystack4 << "\", Needle: \"" << needle4 << "\"" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Actual Output: " << result4 << endl << endl;

    // 測試案例 5
    string haystack5 = "mississippi";
    string needle5 = "issip";
    int result5 = solution.strStr(haystack5, needle5);
    cout << "Test Case 5:" << endl;
    cout << "Haystack: \"" << haystack5 << "\", Needle: \"" << needle5 << "\"" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Actual Output: " << result5 << endl << endl;

    return 0;
}