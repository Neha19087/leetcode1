class Solution {
public:
    void permutations(vector<int>& nums,vector<bool>& visited,vector<vector<int>>& ans,vector<int>ds){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                visited[i]=true;
                ds.push_back(nums[i]);
                permutations(nums,visited,ans,ds);
                ds.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<bool>visited(n,false);
        vector<int>ds;
        permutations(nums,visited,ans,ds);
        return ans;
    }
};