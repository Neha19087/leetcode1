class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        int minlen=INT_MAX;
        for(int i=0;i<n;i++){
            minlen=min(minlen,(int)strs[i].size());

        }
        string s;
        for(int i=0;i<minlen;i++){
            for(int j=1;j<n;j++){
                if(strs[j][i]!=strs[j-1][i]){
                    return s;
                }
            }
            s+=strs[0][i];
        }
        return s;
    }
};