class Solution {
public:

    bool isPossible(int r, int c, char ch, vector<vector<char>>& board){
        // row column
        for(int i = 0; i<9; i++){
            if(board[r][i] == ch) return false;
            if(board[i][c] == ch) return false; 
        }

        // 3x3 grid
        int sr = 3 * (r/3);
        int sc = 3 * (c/3);

        for(int i = sr; i < (sr + 3); i++){
            for(int j = sc; j < (sc + 3); j++){
                if(board[i][j] == ch) return false;
            }
        }

        return true;
    }

    bool helper(int r, int c, vector<vector<char>>& board){
        if(r == 9){
            return true;
        }

        bool ans = false;
        if(board[r][c] == '.'){
            for(int i = 1; i <= 9; i++){    // values
                char ch = i + '0';
                if(isPossible(r, c, ch, board)){
                    board[r][c] = ch;
                    if(c+1 == 9){
                        ans = helper(r+1, 0, board);
                    }else{
                        ans = helper(r, c+1, board);
                    }

                    if(ans) return true;

                    // backtrack(if ans is false)
                    board[r][c] = '.';
                }
            } 

            return false;
        }
        else{
            if(c+1 == 9){
                ans = helper(r+1, 0, board);
            }else{
                ans = helper(r, c+1, board);
            }
        }

        return ans;

    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0, board);
    }
};