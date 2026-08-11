class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxel=INT_MIN;
        int maxind=0;
        vector<int>arr(nums.size(),0);
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxel){
                maxel=nums[i];
                maxind=i;
            }
        }
        st.push(nums[maxind]);
        for(int i= maxind;i>=0;i--){
            if(nums[i]==maxel){
                arr[i]=-1;
            }
            else{
                while(st.top()<=nums[i]){
                    st.pop();
                }
                arr[i]=st.top();
            }
            st.push(nums[i]);

        }
        if(maxind<nums.size()-1){
            for(int i= nums.size()-1;i>maxind;i--){
                if(nums[i]==maxel){
                    arr[i]=-1;
                }
                else{
                    while(st.top()<=nums[i]){
                        st.pop();
                    }
                    arr[i]=st.top();
                }
                st.push(nums[i]);
            }
        }
        return arr;
        
    }
};