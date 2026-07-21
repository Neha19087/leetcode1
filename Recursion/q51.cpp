class Solution {
public:
    void helper(vector<vector<string>>& ans,vector<string>& board,int col,vector<int>& adjacent_row,vector<int>& lowerdiagonal,vector<int>& upperdiagonal){
        if(col==board.size()){
            ans.push_back(board);
        }
        for(int row=0;row<board.size();row++){
            if(adjacent_row[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[board.size()-1+row-col]==0){
                board[row][col]='Q';
                adjacent_row[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[board.size()-1+ row-col]=1;
                helper(ans,board,col+1,adjacent_row,lowerdiagonal,upperdiagonal);
                board[row][col]='.';
                adjacent_row[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[board.size()-1+row-col]=0;
            }                                                    
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        vector<string> board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        vector<int>adjacent_row(n,0);
        vector<int>lowerdiagonal(2*n+1,0);
        vector<int>upperdiagonal(2*n+1,0);
        vector<vector<string>> ans;
        helper(ans,board,0,adjacent_row,lowerdiagonal,upperdiagonal);
        return ans;
    }
};