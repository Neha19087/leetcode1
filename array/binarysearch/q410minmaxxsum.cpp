//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
//Return the minimized largest sum of the split.
//A subarray is a contiguous part of the array
//we have to minimise the max sum of any subarray here
class Solution {
public:
    int splitArray(vector<int> &nums, int k)  {
        int n= nums.size();
        int mini=INT_MAX;
        int sumi=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            sumi+=nums[i];
            mini= min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        if(n==k){
            return maxi;
        }
        if(k==1) return sumi;
        int low=maxi;
        int high=sumi;
        int mid=0;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            int maxsum=0;
            int nosplit=0;
            for(int i=0;i<n;i++){
                maxsum+=nums[i];
                if(nums[i]>=mid){
                    if(i!=0 && maxsum>nums[i]){
                        nosplit++;
                    }
                    nosplit++;
                    maxsum=0;
                    continue;
                }
                if( maxsum>mid){
                    nosplit++;
                    maxsum=nums[i];
                }
                else if(maxsum==mid){
                    nosplit++;
                    maxsum=0;
                }
            }
            if(maxsum!=0){
                nosplit++;
            }
            if(nosplit<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};