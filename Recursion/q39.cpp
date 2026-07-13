class Solution {
public:
    vector<vector<int>>findcomb(int index,int target,vector<int>candidates,vector<vector<int>>ans,vector<int>ds){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ans;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            ans=findcomb(index,target-candidates[index],candidates,ans,ds);
            ds.pop_back();
        }
        ans=findcomb(index+1,target,candidates,ans,ds);
        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n= candidates.size();
        int index=0;
        ans=findcomb(index,target,candidates,ans,ds);
        return ans;
    }
};