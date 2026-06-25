class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.size();
        int m= t.size();
        if(n!=m){
            return false;
        }
        int arr[26];
        for(int i=0;i<n;i++){
            arr[s[i]-97]++;
        }
        for(int i=0;i<n;i++){
            if(arr[t[i]-97]==0){
                return false;
            }
            arr[t[i]-97]--;
        }
        return true;
    }
};