#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        vector<int>arr;
        int i=0;
        arr.push_back(nums[0]);
        for (int j=1; j<n; j++){
            if (nums[j]!= nums[i]){
                arr.push_back(nums[j]);
                i=j;
            }
        }
        nums= arr;
        return nums.size(); 
        
}
int main(){
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    int k= removeDuplicates(nums);
    cout<<k;

}
