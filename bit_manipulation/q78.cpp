//power set
class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int index,vector<int>& ds){
        if(index==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[index]);
        helper(nums,ans,index+1,ds);
        ds.pop_back();
        helper(nums,ans,index+1,ds);
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        helper(nums,ans,0,ds);
        return ans;
    }
};
