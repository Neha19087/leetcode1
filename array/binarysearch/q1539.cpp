//Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
//Return the kth positive integer that is missing from this array. 
//Example 1:
//Input: arr = [2,3,4,7,11], k = 5
//Output: 9
//Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

// brute force method can be to initially set ans as k and iterate the array and incrementing ans each time a no smaller than ans is encountered
// better method will be to use binary search
// we can find the no of missing elements at each point by subtracting (nums[i]- i-1)
// then perform binary search to from index 0 to n-1 and find the interval that contains req missing no
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int low=0;
        int high=n-1;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            int missing= arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low+k;
    }
};