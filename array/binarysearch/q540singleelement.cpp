// we are given an array where each element excepty one occurs twice
//brute force solution will be to use a nested loop to find if another element exists for that element
// time complexity will be O(n^2)
// better solution will be to use xor on array , only single element will remain as x xor x =0
// time complexity will be O(n)
// another method will be to use hashmap and store frequency of each element
// best method will be to use binary search
// time complexity will be O(logn)
// use the pattern (even,odd), (even,odd) , (single), (odd,even), (odd,even)
// if(even,odd) pattern exists for mid, single element exists in right subarray otherwise left
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];      
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1;
        int high=n-2;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]){             // mid element is not equal to any element around it and hence is the single element
                return nums[mid];
            }
            if((mid%2==0 && nums[mid]==nums[mid+1]) || mid%2==1 && nums[mid]== nums[mid-1]){         // even,odd therefore consider right subarray       
                low= mid+1;
            }
            else{
                high= mid-1;                                   //otherwise left
            }
        }
        return -1;
    }
};