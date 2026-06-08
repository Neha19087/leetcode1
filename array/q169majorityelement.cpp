#include <bits/stdc++.h>
using namespace std;
// we have to find the majority element of the array 
//that occurs more than n/2 times in an array
//brute method will be to iterate the array multiple times and checking for each element its no of occurances
//better method would be to use hash map and store the count of each element 
// as the count of any element exceed n/2 it is returned
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>n/2){
                return nums[i];
            }
        }
        return -1;
    }
};

// most optimal method would be to use Moore majority vote algoritm
//for the starting element we will upvote it at each occurance and downvote it at occurance of any other element
// if after downvote votes reach 0 then we restart the voting by taking the next element as the candidate

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if( cnt==0){
                ele=nums[i];
            }
            if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ele;
    }
};