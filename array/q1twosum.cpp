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
