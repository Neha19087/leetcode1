class Solution{
    public:
    void helper(vector<vector<int> > &grid,vector<string>& ans,string& ds,int row,int col){
        if(row==grid.size()-1 && col==grid.size()-1){
            ans.push_back(ds);
            return;
        }
        if(col+1<grid.size() && grid[row][col+1]==1){
            ds.push_back('R');
            helper(grid,ans,ds,row,col+1);
            ds.pop_back();
        }
        if(row+1<grid.size() && grid[row+1][col]==1){
            ds.push_back('D');
            helper(grid,ans,ds,row+1,col);
            ds.pop_back();
        }
        return;
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        vector<string> ans;
        if(grid[0][0]==0){
            return ans;
        }
        string ds;
        helper(grid,ans,ds,0,0);
        return ans;
    }
};