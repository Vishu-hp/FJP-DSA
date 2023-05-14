// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    bool isValid(vector<vector<char>>&board,int r,int c,char v){
        // row
        for(int i=0;i<board[0].size();i++){
            if(board[r][i] == v){
                return false;
            }
        }

        // column
        for(int i=0;i<board.size();i++){
            if(board[i][c] == v){
                return false;
            }
        }

        // subarray
        r = r/3 * 3;
        c = c/3 * 3;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[r+i][c+j]==v){
                    return false;
                }
            }
        }
        return true;
    }

    void solve(vector<vector<char>>&board,int r,int c,vector<vector<char>>&ans){
        if(r == board.size()){
            ans=board;
            return;
        }

        int nr,nc;

        if(c == board[0].size()-1){
            nr = r+1;
            nc = 0;
        }
        else{
            nr = r;
            nc = c+1;
        }

        if(board[r][c]!='.'){
            solve(board,nr,nc,ans);
        }
        else{
            for(char v = '1';v<='9';v++){
                if(isValid(board,r,c,v)){
                    board[r][c] = v;
                    solve(board,nr,nc,ans);
                    board[r][c] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>>ans;
        solve(board,0,0,ans);
        board = ans;
        return;
    }
};
