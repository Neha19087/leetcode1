// we have to find the subarray with max sum
//brute force will be used to find the sum of each subarray by using nested loop 
// time complexity will be O(n^2)

// optimal method will be to use Kadane's algoritm
// it involvs iterating the array and updating sum at each step
//if sum becomes negative at any point we restart the subarray from next element and record the max sum obtained
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_sum=INT_MIN;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if (sum<0){
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            if(max_sum<sum){
                max_sum=sum;
            }
        }
        return max_sum;
    }
};

// if we have to return subarray as well we can do it also just by maintaining two pointers
int maxSubArray(vector<int>& nums){
    int sum=0;
    int start=-1;
    int end=-1;
    int ans_start=-1;
    int ans_final=-1;
    int max_sum=INT_MIN;
    int n=nums.size();
    for (int i=0;i<n;i++){
        if (sum==0){
           start=i;
        }
        sum+= nums[i];
        end=i;
        if(sum>max_sum){
            max_sum=sum;
            ans_start= start;
            ans_final= end;
        }
        if (sum<0){
            sum=0;
        }
       
    }
    return max_sum;
    
}
