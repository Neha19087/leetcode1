#include <bits/stdc++.h>
using namespace std;
// first solution is without using any built in function and iterating just once
//but updating each time 0 is encountered
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int maxi=0;
        int target=0;
        for (int i=0; i<n; i++){
            if (nums[i]==1){
                target+=1;
            }
            else{
                if (maxi<target){
                    maxi=target;
                }
                target=0;
                
            }
        }
        if (maxi<target){
            maxi= target;
        }
        return maxi; 
    }
};
// this code uses built in function max to update the maximum value at each step
int findmax(vector<int>& nums){
    int n= nums.size();
        int maxi=0;
        int target=0;
        for (int i=0; i<n; i++){
            if (nums[i]==1){
                target+=1;
                maxi= max(maxi, target);
            }
            else{
                target=0;
            }
        }
    
        return maxi;
}