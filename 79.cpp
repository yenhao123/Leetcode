class Solution {
    int n, m;
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& isVisited, string word, int wordidx, int row, int col) {
        if (wordidx >= word.size()) return true;
        isVisited[row][col] = true;
        bool isExist = false;
        if (col+1 < n && !isVisited[row][col+1] && board[row][col+1] == word[wordidx]) {
            isExist = dfs(board, isVisited, word, wordidx+1, row, col+1); 
            if (isExist) return true;
            isVisited[row][col+1] = false;
        }
        if (col-1 >= 0 && !isVisited[row][col-1] && board[row][col-1] == word[wordidx]) {
            isExist = dfs(board, isVisited, word, wordidx+1, row, col-1);
            if (isExist) return true;
            isVisited[row][col-1] = false;
        }
        if (row+1 < m && !isVisited[row+1][col] && board[row+1][col] == word[wordidx]) {
            isExist = dfs(board, isVisited, word, wordidx+1, row+1, col); 
            if (isExist) return true;
            isVisited[row+1][col] = false;
        }
        if (row-1 >= 0 && !isVisited[row-1][col] && board[row-1][col] == word[wordidx]) {
            isExist = dfs(board, isVisited, word, wordidx+1, row-1, col); 
            if (isExist) return true;
            isVisited[row-1][col] = false;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                bool res = false;
                if (board[row][col] == word[0]) {
                    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
                    res = dfs(board, isVisited, word, 1, row, col);
                    if (res) return true;
                }
            }
        }
        return false;
    }
};