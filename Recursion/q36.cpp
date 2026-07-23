//check if a sudoku is valid or not
class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col){
        int val=board[row][col];
        for(int i=0;i<9;i++){
            if(board[row][i]==val && i!=col) return false;
            if(board[i][col]==val && i!=row) return false;
            if(board[3*(row/3)+ i/3][3*(col/3)+ i%3]==val){
                if((3*(row/3)+ i/3) !=row || (3*(col/3)+ i%3)!= col) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(check(board,i,j)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};