class Solution {
public:
    void findcomb(int index,int k,int n,vector<int>& arr, vector<vector<int>>& ans,vector<int>& ds){
        if(k==0 && n==0){
            ans.push_back(ds);
        }
        if(index==arr.size()) return;
        if(k==0) return;
        if(arr[index]<=n){
            ds.push_back(arr[index]);
            findcomb(index+1,k-1,n-arr[index],arr,ans,ds);
            ds.pop_back();
            findcomb(index+1,k,n,arr,ans,ds);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        for(int i=1;i<=9;i++){
            arr.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>ds;
        findcomb(0,k,n,arr,ans,ds);
        return ans;
    }
};