#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;
/*

//recursive
class Solution {
private:
    unordered_set<string> uset;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict){
            uset.insert(word);
        }
        uset.insert("");
        string seg = "";
        vector<string> seg_all;
        return word_break_recur(s, seg, seg_all);
    }
    bool word_break_recur(string s, string seg, vector<string>& seg_all){
        if(s.size() == 1){
            seg += s;
            seg_all.push_back(seg);
            cout << "---start---" << endl;
            for(auto word : seg_all){
                cout << word << endl;
                auto it = uset.find(word);
                if(it == uset.end()) {
                    seg_all.pop_back();
                    return false;
                }
            }
            seg_all.pop_back();
            cout << "---end---" << endl;
            return true;
        }
        seg += s.substr(0, 1);
        bool undone = word_break_recur(s.substr(1, s.size()), seg, seg_all);
        seg_all.push_back(seg);
        bool done = word_break_recur(s.substr(1, s.size()), "", seg_all);
        seg_all.pop_back();
        return undone || done;
    }
};
*/
/*
class Solution {
private:
    unordered_set<string> uset;
    vector<int> mem;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict){
            uset.insert(word);
        }

        mem = vector<int>(s.size(), -1);
        return word_break_recur(s, 0, 1);
    }
    bool word_break_recur(string s, int start, int end){
        if(mem[start] != -1){
            return mem[start] == 1;
        }
        if(end > s.size() - 1){
            string word = s.substr(start, end-start);
            auto it = uset.find(word);
            if(it != uset.end()) return true;
            else return false;
        }

        //截斷
        string word = s.substr(start, end-start);
        auto it = uset.find(word);
        bool undone = false;
        if(it != uset.end()) {
            undone = word_break_recur(s, end, end+1);
        }
        //未截斷
        bool done = word_break_recur(s, start, end+1);
        bool res = undone || done;
        mem[start] = res ? 1 : 0;
        return res;
    }
};
*/
class Solution {
private:
    unordered_set<string> uset;
    vector<int> mem;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict){
            uset.insert(word);
        }

        mem = vector<int>(s.size(), -1);
        return word_break_recur(s, 0);
    }
    bool word_break_recur(string s, int start){
        if(start == s.size()){
            return true;
        }
        if(mem[start] != -1){
            return mem[start] == 1;
        }

        //截斷
        for(int end = start + 1; end <= s.size(); end++){
            // 檢查 s[start, end) 是否在字典中
            string word = s.substr(start, end-start);
            auto it = uset.find(word);
            if(it != uset.end()) {
                if(word_break_recur(s, end)){
                    mem[start] = 1;
                    return true;
                }
            }
        }
        mem[start] = 0;
        return false;
    }
};

int main() {

    // Test Case 1
    {
        string s = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        Solution sol;
        cout << "Test Case 1: " << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;
    }

    // Test Case 2
    {
        string s = "applepenapple";
        vector<string> wordDict = {"apple", "pen"};
        Solution sol;
        cout << "Test Case 2: " << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;
    }
    
    // Test Case 3
    {
        string s = "catsandog";
        vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
        Solution sol;
        cout << "Test Case 3: " << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;
    }

    // Test Case 4
    {
        string s = "bccdbacdbdacddabbaaaadababadad";
        vector<string> wordDict = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
        Solution sol;
        cout << "Test Case 4: " << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;
    }

    // Test Case 5
    {
        string s = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb";
        vector<string> wordDict = {"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"};
        Solution sol;
        cout << "Test Case 5: " << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;
    }
    return 0;
}
