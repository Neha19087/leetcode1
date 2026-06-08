//we have to sort an array containing only 0s, 1s and 2s
//brute force method would be to use any sorting algorithm gining O(nlogn) time complexity
// better method would be to store no of 0s, 1s and 2s while iterating in the array and then replacing accordingly
// time complexity will be O(nlogn) 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int zeros=0;
        int ones=0;
        int twos=0;
        for(int i=0;i<n;i++){
            if (nums[i]==0){
                zeros+=1;
            }
            else if(nums[i]==1){
                ones+=1;
            }
            else{
                twos+=1;
            }
        }
        for(int i=0; i<zeros;i++){
            nums[i]=0;
        }
        for(int i=zeros; i<zeros+ones; i++){
            nums[i]=1;
        }
        for(int i=zeros+ones; i<n; i++){
            nums[i]=2;
        }
    }
};

// most optimal method will be of dutch's flag algorithm
// it uses three pointers low, mid and high
//0s from 0 to low-1
// 1s from low to mid-1
// mid to high unsorted subarray
// 2s from high +1 to n-1
//we will see the element at mid and swap accordingly
// if its 0 , swap with low and increment low and mid
// if its 1 , its at correct position , just increment mid
// if its 2, swap high and mid and decrement high
// time complexity will be O(n)
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        for(int i=0;i<n;i++){
            if (nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
        
    }
};