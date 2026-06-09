#include <bits/stdc++.h>
using namespace std;
// we have to find the best day to buy and sell shares given the prices of shares on distinct days
//brute force would be to find the profit from each transaction and return the maximum profit 
// time complexity will be O(n^2) 
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int n= nums.size();
        int max_diff=0;
        for (int i=0;i<n-1;i++){
            int diff=0;
            for(int j=i+1; j<n;j++){
                diff=arr[j]-arr[i];
                if(diff>max_diff){
                    max_diff=diff;
                }
            }
        }
        return max_diff;
    }
};

// optimal method will be to store the min element and to update it at each step after finding profit at that step 
// time complexity will be O(n) 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int max_profit=0;
        int mini=prices[0];
        int n= prices.size();
        for (int i=1;i<n;i++){
            profit= prices[i]-mini;
            max_profit= max(profit,max_profit);
            mini=min(mini,prices[i]);
        }
        return max_profit;
    }
};