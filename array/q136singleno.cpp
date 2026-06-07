#include <bits/stdc++.h>
using namespace std;
//brute force method which consisits of counting for each element 
//uses almost O(n^2) time compexity and constant space complexity

int singleNumber(vector<int>& nums){
    int n= nums.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0; j<n;j++){
            if(nums[j]==nums[i]){
                cnt++;
            }
        }
        if (cnt==1){
            return nums[i];
        }
    }
}

int main() {
    int n;
    cin>> n;
    vector<int>nums;
    for (int i=0; i<n;i++){
        int n1;
        cin>>n1;
        nums.push_back(n1);
    }
    int target= singleNumber(nums);
    cout<< target;

}
// better method
// hash mapping
// nlogn time complexity and n space compexity

int singleNumber(vector<int>& nums){
    int n= nums.size();
    map<int,int>mpp;
    for(int i=0; i<n; i++){
        mpp[nums[i]]++;
    }
    for (int i=0; i<n; i++){
        if( mpp[nums[i]]==1){
            return nums[i];
        }
        
    }
    return -1;
}
    
// optimal method 
// uses XOR operator
// linear time complexity and constant space complexity 
class Solution{  
public:    
    int singleNumber(vector<int>& nums){
        int xori=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            xori= xori^nums[i];
        }
        return xori;
        
    }
};
