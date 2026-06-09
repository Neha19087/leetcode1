// we are given an array of integers and we have to find the next permutation of given integers possible
//A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

//For example, for arr = [1,2,3], the following are all the permutations of arr: 
//[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// the next permutation of arr = [1,2,3] is [1,3,2].
//Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
//While the next permutation of arr = [3,2,1] is [1,2,3] 
//because [3,2,1] does not have a lexicographical larger rearrangement.

// brute force method to solve it will be to find out each permutation by recursion
//and store them in a map in a sorted order
// and return the next neighbour of the array asked
// it will take o(n!n) time complexity to find all n! permutations and iterate them
//not feasible

// optimal method is to find the next no formed by the combination of these integers
//find the first adjacent pair from right side where left is smaller than right because if right is already greater
//than left than we cant find a no greater than it  
// if you dont find such a pair reverse the whole array because it is the greatest possible permutation
// swap the left element in the pair with the smallest element greater than that to its right 
// then reverse the subarray from the point next to the swap ( left element in the pair) till the end to get the 
// smallest combination of rest elements to get the just next permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n= nums.size();
        for (int i=n-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if (index==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for (int i=n-1;i>index;i--){
                if (nums[index]<nums[i]){
                    swap(nums[index],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+index+1, nums.end());
        }
    }
};
