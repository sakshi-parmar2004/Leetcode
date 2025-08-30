class Solution {
public:
    bool checkValid(vector<vector<int>>& board) {
              int row = board.size(), col = board[0].size();
       
        for (int i = 0; i < row; i++) {
             unordered_set<char> st1;
            for (int j = 0; j < col; j++) {
                
                if (st1.find(board[i][j]) != st1.end()) {
                    return false;
                }
                st1.insert(board[i][j]);
            }
        }

        
        for (int i = 0; i < col; i++) {
            unordered_set<char> st2;
            for (int j = 0; j < row; j++) {
                if (st2.find(board[j][i]) != st2.end()) {
                    return false;
                }
                st2.insert(board[j][i]);
            }
        }

        return true;
        
    }
};