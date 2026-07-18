class Solution {
public:
    void helper(int opening,int closing,int layer, vector<string>& ans, string& ds){
        if(opening ==0 && closing==0){
            ans.push_back(ds);
            return;
        }
        if(opening!=0){
            ds.push_back('(');
            layer++;
            helper(opening-1,closing,layer,ans,ds);
            ds.pop_back();
            layer--;
        }
        if(closing!=0 && layer>0){
            ds.push_back(')');
            layer--;
            helper(opening,closing-1,layer,ans,ds);
            ds.pop_back();
            layer++;
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ds;
        helper(n,n,0,ans,ds);
        return ans;
    }
};