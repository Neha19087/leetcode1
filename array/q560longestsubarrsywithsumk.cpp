//we have to find the longest subarray whose sum equals to given k
// brute force method uses a nested loop to check sum of subarray starting from given element incrementing the
// length of subarray each time
//it uses almost O(n^2) time complexity
// it can be used both when array consists only positives and zeros or also negatives 
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n= nums.size();
        
        int len=0;
        int maxlen=0;
        for( int i=0;i<n;i++){
            int sum=0;
            for (int j=i;j<n;j++){
                sum+= nums[j];
                if (sum==k){
                    len= j-i+1;
                    maxlen= max(len,maxlen);
                }

            }
        }
        return maxlen;   
    }
};

// better solution is to use prefix sum and hash mapping
// it will use O(nlogn) time complexity if ordered map is used and O(n) time complexity in most cases if unoredered 
// map is used 
// it can be used both when array consists only positives and zeros or also negatives 
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n= nums.size();
        int maxlen=0;
        map<int,int>mpp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if (sum==k){
                maxlen= max(maxlen,i+1);
            }
            int rem= sum-k;
            int left=0;
            if(mpp.find(rem)!=mpp.end()){
                int len=(i-mpp[rem]);
                maxlen= max(len, maxlen);

            }
            if (mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxlen;
        
        
    }
};

// this method can also be used to solve a leetcode problem where we have to count the no of subarrays with sum k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int cnt=0;
        int sum=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            if (sum==k){
                cnt+=1;
            }
            int rem= sum-k;
            if (mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[sum]++;
            
        }
        return cnt;
        
    }
};

// most optimal method to solve this would be by using sliding window algorithm
// but it can only be used when array contains only positives and zeros
// here space complexity will also be constant and time complexity will be linear
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int i=0;
        int j=0;
        int n= nums.size();
        int maxlen=0;
        int len=0;
        int sum =nums[0];
        while(j<n){
            while(i<=j && sum>k){
                sum-=nums[i];
                i++;
            }
            if (sum==k){
                len =j-i+1;
                maxlen= max(len, maxlen);
            }
            j++;
            if (j<n){
                sum+=nums[j];
            }
        }
        return maxlen;
        

    }
};

