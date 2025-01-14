#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
    bool check_pattern(char letter, string substring, unordered_map<char, string>& umap1, unordered_map<string, char>& umap2){
        if(umap1.find(letter) == umap1.end()){
            umap1[letter] = substring;
        }else{
            if(umap1[letter] != substring){
                return false;
            }
        }

        if(umap2.find(substring) == umap2.end()){
            umap2[substring] = letter;
        }
        if(umap2[substring] != letter){
            return false;
        }

        return true;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap1;
        unordered_map<string, char> umap2;
        int pattern_pt = 0;
        int start = 0, end = 0;
        int n_substring = 0;

        // spilt string and check if pattern in the s 
        while((end = s.find(" ", start)) != string::npos){
            if(end != start){
                if(pattern_pt >= pattern.size()){
                    return false;
                }
                char letter = pattern[pattern_pt];
                string substring = s.substr(start, end-start);
                cout << letter << ":" << substring << endl;
                if(!check_pattern(letter, substring, umap1, umap2)){
                    return false;
                }
                pattern_pt += 1;
                n_substring += 1;
            }

            start = end + 1;
        }
        if(start < s.size()){
            if(pattern_pt >= pattern.size()){
                return false;
            }
            char letter = pattern[pattern_pt];
            string substring = s.substr(start, end-start);
            cout << letter << ":" << substring << endl;
            if(!check_pattern(letter, substring, umap1, umap2)){
                return false;
            }
        }

        return true;
    }
};
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap1;
        unordered_map<string, char> umap2;
        int pattern_pt = 0;
        int start = 0, end = 0;
        int n_substring = 0;
        vector<string> substring_arr;

        // spilt string
        while((end = s.find(" ", start)) != string::npos){
            if(end != start){
                substring_arr.push_back(s.substr(start, end-start));
            }
            start = end + 1;
        }
        if(start < s.size()){
            if(end != start){
                substring_arr.push_back(s.substr(start, end-start));
            }
            start = end + 1;
        }
        // check pattern
        if(substring_arr.size() != pattern.size()){
            return false;
        }

        for(int i = 0; i < substring_arr.size(); i++){
            char letter = pattern[i];
            string substring = substring_arr[i];

            if(umap1.find(letter) == umap1.end()){
                umap1[letter] = substring;
            }else{
                if(umap1[letter] != substring){
                    return false;
                }
            }

            if(umap2.find(substring) == umap2.end()){
                umap2[substring] = letter;
            }
            if(umap2[substring] != letter){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    // **Test Case 1**: Expected output: true
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Test Case 1: " << (solution.wordPattern(pattern1, s1) ? "true" : "false") << endl;

    // **Test Case 2**: Expected output: false
    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Test Case 2: " << (solution.wordPattern(pattern2, s2) ? "true" : "false") << endl;

    // **Test Case 3**: Expected output: false
    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Test Case 3: " << (solution.wordPattern(pattern3, s3) ? "true" : "false") << endl;

    // **Test Case 4**: Expected output: false
    string pattern4 = "abba";
    string s4 = "dog dog dog dog";
    cout << "Test Case 4: " << (solution.wordPattern(pattern4, s4) ? "true" : "false") << endl;

    // **Test Case 5**: Edge case: Pattern and string length mismatch. Expected output: false
    string pattern5 = "abc";
    string s5 = "cat dog";
    cout << "Test Case 5: " << (solution.wordPattern(pattern5, s5) ? "true" : "false") << endl;

    // **Test Case 6**: Edge case: Empty string and pattern. Expected output: true
    string pattern6 = "";
    string s6 = "";
    cout << "Test Case 6: " << (solution.wordPattern(pattern6, s6) ? "true" : "false") << endl;

    // **Test Case 7**: Expected output: false
    string pattern7 = "abc";
    string s7 = "dog cat dog";
    cout << "Test Case 7: " << (solution.wordPattern(pattern7, s7) ? "true" : "false") << endl;
}