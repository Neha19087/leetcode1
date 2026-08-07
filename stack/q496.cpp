class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int>ans;
        int n=nums2.size();
        unordered_map<int,int> mpp;
        st.push(nums2[n-1]);
        mpp[nums2[n-1]]=-1;
        for( int i=n-2; i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                if(!st.empty()){
                    mpp[nums2[i]]=st.top();
                }
                else{
                    mpp[nums2[i]]=-1;
                }
            }
            else{
                mpp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;   
    }
};