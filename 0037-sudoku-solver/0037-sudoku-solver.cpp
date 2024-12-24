class Solution {
public:

    bool isPossible(int r, int c, vector<vector<char>>& board, char num){
        // row column
        for(int i = 0; i<9; i++){
            if(board[r][i] == num) return false;
            if(board[i][c] == num) return false;
        }

        int rs = 3*(r/3);
        int cs = 3*(c/3);

        // 3x3 grid
        for(int i = rs; i<(rs+3); i++){
            for(int j = cs; j<(cs+3); j++){
                if(board[i][j] == num) return false;
            }
        }

        return true;
    }

    bool helper(int r, int c, vector<vector<char>>& board){
        // base case
        if(r == 9) return true;
        if(c == 9) return helper(r+1, 0, board);

        // main structure
        if(board[r][c] != '.'){
            return helper(r, c+1, board);
        }

        for(char num = '1'; num <= '9'; num++){
            if(isPossible(r, c, board, num)){
                board[r][c] = num;
                bool res = helper(r, c+1, board);
                
                if(res == true) return true;

                board[r][c] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0, board);
    }
};