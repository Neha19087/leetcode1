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
// but it works only if we are cconfirm that majority element exits
// therefore after implementing algorithm we will check if it is actually majority element or not
// it works on the principle that a majority element cant be cancelled by other elements combined 

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

// for finding elements ocurring morethann n/3 times, brute and better method will be almost same
class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>n/3){
                arr.push_back(it.first);
            }
        }
        return arr;
    }
};

//but for optimal solution we have to make improvements 
// max three majority elements can be there with count >n/3
// Suppose there are  PARTY A , PARTY B and some other small parties in room. The majority criteria 
//(winning criteria) is when a party gets more than n/3 votes. Now assume there are 100 voters in that
// particular room so a party must get 100/3 i.e. more than 33 votes to win.
// Every supporter of small party cancels out one supporter each of Party A and Party B.

//Now after election the result was:
//1. PARTY A - -> 40 Votes (supporters)   // more than 33 votes
//2. PARTY B - - > 35 Votes (supporters)  //more than 33 votes
//3. And rest 25 people support other small parties.

//Now observe: 
//(i) Both parties are in majority (>33 votes).
//(ii) The supporters of small parties can not cancel out the supporters of A and B.
//(iii) Even the small party voters cannot fully cancel or eliminate one of A's or B's supporters.

//WHY SO?
//Because  n/3 se kamm waale supporters , n/3 se zyada waale supporters ko cancel nhi kar skte.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        vector<int>arr;
        int cnt1=0;
        int el1=INT_MIN;
        int cnt2=0;
        int el2=INT_MIN;
        for (int i=0;i<n;i++){
            if(nums[i]==el1){
                cnt1++;
            }
            else if(nums[i]==el2){
                cnt2++;
            } 
            else if(cnt1==0){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                el2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int cnt3=0;
        int cnt4=0;
        for (int i=0;i<n;i++){
            if (nums[i]==el1) cnt3++;
            if (nums[i]==el2) cnt4++;
        }
        if(cnt3>n/3) arr.push_back(el1);
        if(cnt4>n/3) arr.push_back(el2);
        return arr;
    }
};