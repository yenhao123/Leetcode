bool comp(const vector<int> &a, const vector<int> &b)
{
    return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
}

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> tmp(people.size());
        for (int i = 0; i < people.size(); i++)
        {
            int x = people[i][0], y = people[i][1];
            tmp[i].push_back(x);
            tmp[i].push_back(y);
            tmp[i].push_back(i);
        }
        int n = people.size();
        vector<vector<int>> res;
        while (res.size() != n)
        {
            sort(tmp.begin(), tmp.end(), comp);
            res.push_back(people[tmp[0][2]]);
            int xTarget = tmp[0][0], yTarget = tmp[0][1];
            tmp.erase(tmp.begin());
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i][0] <= xTarget)
                {
                    tmp[i][1]--;
                }
            }
        }
        return res;
    }
};