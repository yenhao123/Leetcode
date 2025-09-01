class Solution
{
    vector<string> split(const string &s, char delimiter)
    {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delimiter))
        {
            result.push_back(item);
        }
        return result;
    }

public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();

        vector<int> prevAlt(n);
        int zero = -1, one = -1;
        for (int i = 0; i < n; i++)
        {
            if (groups[i] == 0)
            {
                prevAlt[i] = one;
                zero = i;
            }
            else
            {
                prevAlt[i] = zero;
                one = i;
            }
        }

        vector<string> dp(n);
        for (int i = 0; i < n; i++)
        {
            if (prevAlt[i] != -1)
            {
                dp[i] = dp[prevAlt[i]] + "," + words[i];
            }
            else
            {
                dp[i] = words[i];
            }
            // cout << i << "," << prevAlt[i] << "," << words[i] << endl;
        }

        vector<string> res = split(dp[n - 1], ',');

        return res;
    }
};