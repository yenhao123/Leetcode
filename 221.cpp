class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();

        int maxSquareLength = 0;
        vector<vector<int>> dp(nRows+1, vector<int>(nCols+1, 0));
        maxSquareLength = max(dp[0][0], maxSquareLength);

        for (int row = 1; row <= nRows; row++) {
            for (int col = 1; col <= nCols; col++) {
                if (matrix[row-1][col-1] == '1') {
                    dp[row][col] = min({dp[row-1][col-1], dp[row-1][col], dp[row][col-1]}) + 1;
                }
                
                maxSquareLength = max(dp[row][col], maxSquareLength);
            }
        }
        return maxSquareLength * maxSquareLength;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();

        for (int row = 0; row < nRows; row++) {
            for (int col = 0; col < nCols; col++) {
                matrix[row][col] = charToInt(matrix[row][col]);
            }
        }

        int maxSquareLength = 0;
        vector<vector<int>> dp(nRows, vector<int>(nCols, 0));
        dp[0][0] = matrix[0][0];
        maxSquareLength = max(dp[0][0], maxSquareLength);
        
        for (int row = 1; row < nRows; row++) {
            dp[row][0] = matrix[row][0];
            maxSquareLength = max(dp[row][0], maxSquareLength);
        }

        for (int col = 1; col < nCols; col++) {
            dp[0][col] = matrix[0][col];
            maxSquareLength = max(dp[0][col], maxSquareLength);
        }

        for (int row = 1; row < nRows; row++) {
            for (int col = 1; col < nCols; col++) {
                int subSquareLength = dp[row-1][col-1];
                int squareLength = 0;
                for (int nNextTo = 0; nNextTo <= subSquareLength; nNextTo++) {
                    if (matrix[row-nNextTo][col] == 0) break;
                    if (matrix[row][col-nNextTo] == 0) break;
                    squareLength += 1;
                }
                dp[row][col] = squareLength;
                maxSquareLength = max(dp[row][col], maxSquareLength);
                //cout << row << ":" << col << ":" << squareLength << endl;
            }
        }
        return maxSquareLength * maxSquareLength;
    }

    int charToInt(char c) {
        int a = c - '0';
        return a;
    }
};