
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
/*
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 'O' and non-edge rigion
        int y_dim = board.size();
        int x_dim = board[0].size();
        unordered_set<string> potential_surrounds;

        for(int i = 1; i < y_dim-1; i++){
            for(int j = 1; j < x_dim-1; j++){
               if(board[i][j] == 'O'){
                    string key = to_string(i) + "_" + to_string(j);
                    potential_surrounds.insert(key);
               }
            }
        }
        // check boarder
        for(int i = 0; i < x_dim; i++){
            if(board[0][i] == 'O'){
                stack<pair<int, int>> s;
                s.push({0, i});

                while(!s.empty()){
                    auto [x, y] = s.top();
                    s.pop();
                    pair<int, int> neighbors[] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
                    for (auto [nx, ny] : neighbors) {
                        string key = to_string(nx) + "_" + to_string(ny);
                        if (potential_surrounds.find(key) != potential_surrounds.end()) {
                            s.push({nx, ny});
                            potential_surrounds.erase(key); 
                        }
                    }
                }
            }
            if(board[y_dim-1][i] == 'O'){
                stack<pair<int, int>> s;
                s.push({y_dim-1, i});
                while(!s.empty()){
                    auto [x, y] = s.top();
                    s.pop();
                    pair<int, int> neighbors[] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
                    for (auto [nx, ny] : neighbors) {
                        string key = to_string(nx) + "_" + to_string(ny);
                        if (potential_surrounds.find(key) != potential_surrounds.end()) {
                            s.push({nx, ny});
                            potential_surrounds.erase(key); 
                        }
                    }
                }
            }          
        }

        for(int i = 0; i < y_dim; i++){
            if(board[i][0] == 'O'){
                stack<pair<int, int>> s;
                s.push({i, 0});

                while(!s.empty()){
                    auto [x, y] = s.top();
                    s.pop();
                    pair<int, int> neighbors[] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
                    for (auto [nx, ny] : neighbors) {
                        string key = to_string(nx) + "_" + to_string(ny);
                        if (potential_surrounds.find(key) != potential_surrounds.end()) {
                            s.push({nx, ny});
                            potential_surrounds.erase(key); 
                        }
                    }
                }
            }
            if(board[i][x_dim-1] == 'O'){
                stack<pair<int, int>> s;
                s.push({i, x_dim-1});
                
                while(!s.empty()){
                    auto [x, y] = s.top();
                    s.pop();
                    pair<int, int> neighbors[] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
                    for (auto [nx, ny] : neighbors) {
                        string key = to_string(nx) + "_" + to_string(ny);
                        if (potential_surrounds.find(key) != potential_surrounds.end()) {
                            s.push({nx, ny});
                            potential_surrounds.erase(key); 
                        }
                    }
                }
            }
        }

        // O -> X
        for(auto idx : potential_surrounds){
            size_t underscore_pos = idx.find('_');
            int i = std::stoi(idx.substr(0, underscore_pos));
            int j = std::stoi(idx.substr(underscore_pos + 1));
            board[i][j] = 'X';
        }
    }
};
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 'O' and non-edge rigion
        int y_dim = board.size();
        int x_dim = board[0].size();

        // mark all candidate which 'O' in the border
        for(int i = 1; i < y_dim-1; i++){
            for(int j = 1; j < x_dim-1; j++){
               if(board[i][j] == 'O'){
                    board[i][j] = 'T';
               }
            }
        }
        // check boarder
        for(int i = 0; i < x_dim; i++){
            if (board[0][i] == 'O') markBorderConnected(board, 0, i, y_dim, x_dim);
            if (board[y_dim - 1][i] == 'O') markBorderConnected(board, y_dim - 1, i, y_dim, x_dim);    
        }

        for(int i = 0; i < y_dim; i++){
            if (board[i][0] == 'O') markBorderConnected(board, i, 0, y_dim, x_dim);
            if (board[i][x_dim - 1] == 'O') markBorderConnected(board, i, x_dim - 1, y_dim, x_dim);
        }

        // O -> X
        for (int i = 0; i < y_dim; i++) {
            for (int j = 0; j < x_dim; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private:
    void markBorderConnected(vector<vector<char>>& board, int x, int y, int y_dim, int x_dim) {
        stack<pair<int, int>> s;
        s.push({x, y});

        while (!s.empty()) {
            auto [cur_x, cur_y] = s.top();
            s.pop();
            pair<int, int> neighbors[] = {{cur_x - 1, cur_y}, {cur_x + 1, cur_y}, {cur_x, cur_y - 1}, {cur_x, cur_y + 1}};

            for (auto [nx, ny] : neighbors) {
                if (nx >= 0 && nx < y_dim && ny >= 0 && ny < x_dim && board[nx][ny] == 'T') {
                    s.push({nx, ny});
                    board[nx][ny] = 'O'; // 標記連通的 'O'
                }
            }
        }
    }
};
// 測試方法
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    // 測試用例 1：典型包圍場景
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    cout << "Test Case 1 - Before:" << endl;
    printBoard(board1);
    solution.solve(board1);
    cout << "Test Case 1 - After:" << endl;
    printBoard(board1);

    // 測試用例 2：無邊界 'O'
    vector<vector<char>> board2 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    cout << "Test Case 2 - Before:" << endl;
    printBoard(board2);
    solution.solve(board2);
    cout << "Test Case 2 - After:" << endl;
    printBoard(board2);

    // 測試用例 3：全是 'O'
    vector<vector<char>> board3 = {
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'}
    };
    cout << "Test Case 3 - Before:" << endl;
    printBoard(board3);
    solution.solve(board3);
    cout << "Test Case 3 - After:" << endl;
    printBoard(board3);

    // 測試用例 4：邊界 'O' 不會改變
    vector<vector<char>> board4 = {
        {'O', 'O', 'O', 'O'},
        {'O', 'X', 'X', 'O'},
        {'O', 'X', 'X', 'O'},
        {'O', 'O', 'O', 'O'}
    };
    cout << "Test Case 4 - Before:" << endl;
    printBoard(board4);
    solution.solve(board4);
    cout << "Test Case 4 - After:" << endl;
    printBoard(board4);

    vector<vector<char>> board5 = {
            {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
            {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
            {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
            {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
            {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
            {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X', 'O'},
            {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X'},
            {'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'}
        };
    cout << "Test Case 5 - Before:" << endl;
    printBoard(board5);
    solution.solve(board5);
    cout << "Test Case 5 - After:" << endl;
    printBoard(board5);
    return 0;
}