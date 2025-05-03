int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int toptop = 0, bottop = 0;
    for (int i = 0; i < tops.size(); i++) {
        if (tops[i] != tops[0] && bottoms[i] != tops[0]) {
            toptop = INT_MAX;
            bottop = INT_MAX;
            break;
        }
        if (tops[i] != tops[0] && bottoms[i] == tops[0]) toptop++;
        if (bottoms[i] != tops[0] && tops[i] == tops[0]) bottop++;
    }

    int topbot = 0, botbot = 0;
    for (int i = 0; i < tops.size(); i++) {
        if (tops[i] != bottoms[0] && bottoms[i] != bottoms[0]) {
            topbot = INT_MAX;
            botbot = INT_MAX;
            break;
        }
        if (tops[i] != bottoms[0] && bottoms[i] == bottoms[0]) topbot++;
        if (bottoms[i] != bottoms[0] && tops[i] == bottoms[0]) botbot++;
    }

    int res = min({toptop, bottop, topbot, botbot});
    return res == INT_MAX ? -1 : res;
}