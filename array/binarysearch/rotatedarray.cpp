// we are given a sorted array but it is also rotated
// we cant do direct binary search
//after finding mid we can be sure that atleast one array will be sorted either left of mid or right of mid
// if left array is sorted we can directly check if target lies between nums[low] and nums[mid]
// if not then check right subarray 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if (nums[mid]==target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){                     // to check if left array is sorted
                if(nums[low]<=target && target<=nums[mid]){   // to check if target lies in this sorted left subarray
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){             // to check if target lies in this sorted right subarray
                    low=mid+1;                                          // as left subarray was not sorted, right will be sorted for sure
                }
                else{
                    high=mid-1;
                }

            }
        }
        return -1;
    }
};


// now we have to check for the presense of a target in a rotated sorted array containing duplicates
// above code cant be used for arrays such as [3,1,2,3,3,3,3]
// as above code will return left subarray as non sorted
// only one modification is required in above code
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if (nums[mid]==target){
                    return true;
            }
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){                // to trim the unnecessary part of the array
                low=low+1;
                high=high-1;
                continue;
            }
            else{
                
                if(nums[low]<=nums[mid]){
                    if(nums[low]<=target && target<=nums[mid]){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                else{
                    if(nums[mid]<=target && target<=nums[high]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }

                }
            }
        }
        return false;
    }
};