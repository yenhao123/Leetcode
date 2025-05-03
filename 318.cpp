class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> maxValue(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            unordered_set<char> str1;
            for (auto letter : words[i]) {
                str1.insert(letter);
            }

            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                bool is_pair = true;
                for (auto letter : words[j]) {
                    if (str1.find(letter) != str1.end()) is_pair = false;
                }
                int product = words[i].size() * words[j].size();
                if (is_pair) maxValue[i] = max(maxValue[i], product);
            }   
        }

        int res = maxValue[0];
        for (int i = 1; i < maxValue.size(); i++) {
            res = max(res, maxValue[i]);
        }
        return res;
    }
};