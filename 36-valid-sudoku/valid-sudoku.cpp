class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        int row = board.size(), col = board[0].size();
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') continue; // skip empty cells

                char num = board[i][j]; // use the char directly

                string row_num = string(1, num) + " in row " + to_string(i);
                string col_num = string(1, num) + " in col " + to_string(j);
                string box = string(1, num) + " in box " + to_string(i/3) + "-" + to_string(j/3);

                if (st.find(row_num) != st.end() || 
                    st.find(col_num) != st.end() || 
                    st.find(box) != st.end()) {
                    return false;
                }

                st.insert(row_num);
                st.insert(col_num);
                st.insert(box);
            }
        }
        return true;
    }
};
