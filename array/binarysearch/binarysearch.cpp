//this is the basic code of binary search that finds an element in an array in O(logn) time
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>target){
                high= mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};

// lower bound = smallest index such that arr[index]>=x
//upper bound = smallest index such that arr[index]>x
// floor= largest element in the array <=x
// ceiling = smallest element in the array >= x
// by slight modification in binary search code we can get the code for each
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        while(low<=high){
            mid= (low+high)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>target){
                high= mid-1;
            }
            else{
                return mid;
            }
        }
        return low;
        
    }
};

// to get the first and last occurance of an element in an array of duplicate elements 
// first= lower bound, last= upper bound-1
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