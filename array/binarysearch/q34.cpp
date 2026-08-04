class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        if (n==0) return {-1,-1};
        int low=0;
        int high=n-1;
        int first=-1;
        int last=-1;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high= mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(first==-1){
            return {-1,-1};
        }
        low=0;
        high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high= mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {first,last};
    }
};