class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long total = 0;
        unordered_map<char, bool> voewls = {{'a', false}, {'e', false}, {'i', false}, {'o', false}, {'u', false}};
        int nSatisfiedVoewl = 0;
        unordered_set<char> consonants;
        int nSatisfiedConsonant = 0;
        for(int i = 0; i < word.size(); i++) {
            char letter = word[i];
            if(voewls.find(letter) == voewls.end()) {
                if(nSatisfiedConsonant == 0 && consonants.find(letter) == consonants.end()) {
                    init_var(nSatisfiedConsonant, consonants, nSatisfiedVoewl, voewls);
                } else {
                    // update consonant state
                    nSatisfiedConsonant += 1;
                    consonants.insert(letter);
                }
            } else {
                if(!voewls[letter]) nSatisfiedVoewl += 1;
                voewls[letter] = true;
            }

            // check whether substring satisfing conditions
            if(nSatisfiedConsonant == k && nSatisfiedVoewl == 5) {
                total += 1;
                init_var(nSatisfiedConsonant, consonants, nSatisfiedVoewl, voewls);
            }
        }
        
        return total;
    }

    void init_var(int& nSatisfiedConsonant, unordered_set<char>& consonants, int& nSatisfiedVoewl, unordered_map<char, bool>& voewls) {
        nSatisfiedConsonant = 0;
        consonants.clear();
        nSatisfiedVoewl = 0;
        vector<char> vowels_vec = {'a', 'e', 'i', 'o', 'u'};
        for(auto voewl : vowels_vec) {
            voewls[voewl] = false;
        }
    }
};

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long total = 0;
        unordered_map<char, bool> voewls = {{'a', false}, {'e', false}, {'i', false}, {'o', false}, {'u', false}};
        int nSatisfiedVoewl = 0;
        int nSatisfiedConsonant = 0;
        for(int i = 0; i < word.size(); i++) {
            char letter = word[i];
            if(voewls.find(letter) == voewls.end()) {
                if(nSatisfiedConsonant == k) {
                    nSatisfiedConsonant = 0;
                } else {
                    nSatisfiedConsonant += 1;
                }
            } else {
                if(!voewls[letter]) nSatisfiedVoewl += 1;
                voewls[letter] = true;
            }

            // check whether substring satisfing conditions
            if(nSatisfiedConsonant == k && nSatisfiedVoewl == 5) {
                total += 1;
                nSatisfiedConsonant = 0;
            }
        }
        
        return total;
    }
};
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = word.size();
        long long count = 0;

        int left = 0;  // Sliding window left pointer
        unordered_map<char, int> vowelCount;6
        int consonantCount = 0;
        int validStart = -1; // Stores the first valid window start index

        for (int right = 0; right < n; right++) {
            // Expand the window
            if (vowels.count(word[right])) {
                vowelCount[word[right]]++;
            } else {
                consonantCount++;
            }

            // Shrink window if consonants exceed k
            while (consonantCount > k) {
                if (vowels.count(word[left])) {
                    vowelCount[word[left]]--;
                    if (vowelCount[word[left]] == 0) {
                        vowelCount.erase(word[left]);
                    }
                } else {
                    consonantCount--;
                }
                left++;
            }

            // If all vowels are present and consonants count is exactly k
            if (vowelCount.size() == 5 && consonantCount == k) {
                validStart = left;
            }

            // Count valid substrings ending at 'right'
            if (validStart != -1) {
                count += (validStart - left + 1);
            }
        }

        return count;
    }
};
