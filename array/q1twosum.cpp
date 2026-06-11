//this is brute force method which uses a nested array to iterate the whole array to find if the complement of 
// selected index exists such that their sum equals to target
//time complexity is almost O(n^2)
#include <bits/stdc++.h>
using namespace std;
 vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                if (nums[j]== target- nums[i]){
                    return {i,j};
                    break;
                }
                
            }
           
        }
        return {};
    }
int main(){
    vector<int>nums;
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(7);
    nums.push_back(3);
    int target= 8;
    vector<int>arr;
    arr= twoSum(nums, target);
    for (auto it:arr){
        cout<< it<<" ";
    }
}
// better solution for it would be using hash map to track each element in the array
//time complexity is almost O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int rem= target- nums[i];
            if (mpp.find(rem)!=mpp.end()){
                return {i,mpp[rem]};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};

// this is an optimal solution involving two pointer method which can be used only when array is sorted 
//time complexity is almost O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int left=0;
        int right=n-1;
        while(left<right){
            if (numbers[left]+numbers[right]<target){
                left++;
            }
            else if(numbers[left]+numbers[right]>target){
                right--;
            }
            else{
                return {left, right};
            }               
            
        }
        return {};
        
    }
};

// same problem can be extended to three sum or four sum
// to find three unique index elements whose sum is equal to target(here 0) 
//brute force method will be to run three nested loops to iterate the array thrice to get all 
//possible triplets and check if their sum is equal to required value
//we will sort these triplets and store in a set to prevent duplicates
//it will take(n^3logn) time complexity 

//better method will be to maintain a hashset and two pointers while storing all the elements 
//between these pointers in a hashset and incrementing these pointers using two nested loops
//while maintaining a set to avoid duplicate triplets
//time complexity will be O(n^2logn) 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        set<vector<int>>st;
        for(int i=0; i<n;i++){
            set<int>hashset;
            for(int j=i+1;j<n;j++){
                int rem= -(nums[i]+nums[j]);
                if( hashset.find(rem)!=hashset.end()){
                    vector<int>temp= {nums[i],nums[j],rem};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
 
//optimal method will be to use a two pointer (one at start one at end) approach on a sorted array
//using same logic as two sum i.e. if sum is less than target than move the left pointer foreward
// if sum is more than move the right pointer backward 
//time complexity will be O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){       //to avoid iterating for same element
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum =nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;    // to avoid addind same triplet
                    while(j<k && nums[k]==nums[k+1]) k--;
                }

            }
        }
        return ans;      
    }
};

// same can be done for 4sum with O(n^3) time complexity
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int l=i+1;l<n;l++){
                if(l>i+1 && nums[l]==nums[l-1]){
                continue;
                }
                int j=l+1;
                int k=n-1;
                while(j<k){
                    long long sum =nums[i]+nums[l];
                    sum+=nums[j]+nums[k];
                    if(sum>target){
                        k--;
                    }
                    else if(sum<target){
                        j++;
                    }
                    else{
                        vector<int>temp={nums[i],nums[l],nums[j],nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1]) k--;
                    }
                }

            }
        }
        return ans;    
    }
};
