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
// better solution for it would be using hash map
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