#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int cur_idx = 0;
        int total = 0;
        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        while(cur_idx < s.size()){
            int sub_flag = false;
            int value = 0;
            if(cur_idx+1 < s.size()){
                if(s[cur_idx] == 'I'){
                    if(s[cur_idx+1] == 'V'){
                        value = 4; 
                        sub_flag = true;
                    }else if(s[cur_idx+1] == 'X'){
                        value = 9;
                        sub_flag = true;
                    }
                }else if(s[cur_idx] == 'X'){
                    if(s[cur_idx+1] == 'L'){
                        value = 40; 
                        sub_flag = true;
                    }else if(s[cur_idx+1] == 'C'){
                        value = 90;
                        sub_flag = true;
                    }
                }else if(s[cur_idx] == 'C'){
                    if(s[cur_idx+1] == 'D'){
                        value = 400; 
                        sub_flag = true;
                    }else if(s[cur_idx+1] == 'M'){
                        value = 900;
                        sub_flag = true;
                    }
                }
            }
            if(!sub_flag){
                value = umap[s[cur_idx]];
            }else{
                cur_idx += 1;
            }
            total += value;
            cur_idx += 1;
        }
        return total;
    }
};