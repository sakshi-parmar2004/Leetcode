class Solution {
public:
    bool solve(int sr, int er, int sc, int ec, vector<vector<char>>& board) {
        unordered_set<char> st;
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                 if (board[i][j] == '.') {
                    continue;
                }
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
       
        for (int i = 0; i < row; i++) {
             unordered_set<char> st1;
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (st1.find(board[i][j]) != st1.end()) {
                    return false;
                }
                st1.insert(board[i][j]);
            }
        }

        
        for (int i = 0; i < col; i++) {
            unordered_set<char> st2;
            for (int j = 0; j < row; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (st2.find(board[j][i]) != st2.end()) {
                    return false;
                }
                st2.insert(board[j][i]);
            }
        }

        for (int i = 0; i < row; i += 3) {
            int er = i + 2;
            for (int j = 0; j < col; j += 3) {
                int ec = j + 2;
                if (!solve(i, er, j, ec, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};