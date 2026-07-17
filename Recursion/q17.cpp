class Solution {
public:
    void comb(int index,unordered_map<int,vector<char>>& mpp,string digits,vector<string>& ans,string& ds){
        if(index==digits.size()){
            ans.push_back(ds);
            return;
        } 
        int digit= digits[index]-'0';
        for(int i=0;i<mpp[digit].size();i++){
            ds.push_back(mpp[digit][i]);
            comb(index+1,mpp,digits,ans,ds);
            ds.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string ds;
        unordered_map<int,vector<char>> mpp;
        mpp[2]= {'a','b','c'};
        mpp[3]= {'d','e','f'};
        mpp[4]={'g','h','i'};
        mpp[5]={'j','k','l'};
        mpp[6]={'m','n','o'};
        mpp[7]={'p','q','r','s'};
        mpp[8]={'t','u','v'};
        mpp[9]={'w','x','y','z'};
        int n= digits.size();
        comb(0,mpp,digits,ans,ds);
        return ans;
    }
};
