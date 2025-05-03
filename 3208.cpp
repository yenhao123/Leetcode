class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int nColors = colors.size();
        int alterGroups = 0;
        int i, j;
        for (i = 0; i < nColors; i++) {
            for (j = i+1; j < i+k; j++) {
                if (colors[j%nColors] == colors[(j-1)%nColors]) break;
            }
            if (j >= i+k) alterGroups += 1;
        }
        return alterGroups;
    }
};