class Solution {
public:
    bool search(vector<vector<char>>& board, string word,vector<vector<bool>>& check,int pos,int row,int col){
        if(pos==word.size()) return true;
        if(col-1>=0 && board[row][col-1]==word[pos] && check[row][col-1]==false){
            check[row][col-1]=true;
            if(search(board,word,check,pos+1,row,col-1)) return true;
            else{
                check[row][col-1]=false;
            }
        }
        if(col+1<board[0].size() && board[row][col+1]==word[pos] && check[row][col+1]==false){
            check[row][col+1]=true;
            if(search(board,word,check,pos+1,row,col+1)) return true;
            else{
                check[row][col+1]=false;
            }
        }
        if(row-1>=0 && board[row-1][col]==word[pos] && check[row-1][col]==false){
            check[row-1][col]=true;
            if(search(board,word,check,pos+1,row-1,col)) return true;
            else{
                check[row-1][col]=false;
            }
        }
        if(row+1<board.size() && board[row+1][col]==word[pos] && check[row+1][col]==false){
            check[row+1][col]=true;
            if(search(board,word,check,pos+1,row+1,col)) return true;
            else{
                check[row+1][col]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();   //no of rows
        int n=board[0].size();    //no of columns
        vector<vector<bool>> check;
        vector<bool> row;
        for(int i=0;i<n;i++){
            row.push_back(false);
        }
        for(int i=0;i<m;i++){
            check.push_back(row);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    check[i][j]=true;
                    if(search(board,word,check,1,i,j)==true){
                        return true;
                    }
                    else{
                        check[i][j]=false;
                    }
                }
            }
        }
        return false;
    }
};