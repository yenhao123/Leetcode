
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, bool>> row_check_list(9);
        vector<unordered_map<char, bool>> col_check_list(9);
        vector<unordered_map<char, bool>> block_check_list(9);

        for(int row_idx = 0; row_idx < 9; row_idx++){
            for(int col_idx = 0; col_idx < 9; col_idx++){
                char c = board[row_idx][col_idx];
                int block_idx = row_idx / 3 * 3 + col_idx / 3;
                if(c == '.'){
                    continue;
                }
                if(row_check_list[row_idx][c] || col_check_list[col_idx][c] || block_check_list[block_idx][c]){
                    //cout << row_idx << col_idx << block_idx << endl;
                    //cout << row_check_list[row_idx][c] << col_check_list[col_idx][c] << block_check_list[block_idx][c] << endl;
                    return false;
                }
                row_check_list[row_idx][c] = true;
                col_check_list[col_idx][c] = true;
                block_check_list[block_idx][c] = true;
            }
        }
        return true;
    }
};


int main() {
    Solution solution;

    // Test Case 1: Valid Sudoku Board
    vector<vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << "Test Case 1: " << (solution.isValidSudoku(board1) ? "Valid" : "Invalid") << endl;

    // Test Case 2: Invalid Sudoku Board (Duplicate in Row)
    vector<vector<char>> board2 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'5', '.', '.', '.', '8', '.', '.', '7', '9'}  // Duplicate '5' in the last row
    };
    cout << "Test Case 2: " << (solution.isValidSudoku(board2) ? "Valid" : "Invalid") << endl;
}