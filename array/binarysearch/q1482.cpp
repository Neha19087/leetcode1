//You are given an integer array bloomDay, an integer m and an integer k.
//You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
//The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
//Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
//If it is impossible to make m bouquets return -1.

// brute force will be to run a while loop from 1 and icrementing it by one each time  and finding the min days req to make the bouquets

// better method will bw to use binary search as range of answer is fixed between 1 to max of array
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) { 
        int n= bloomDay.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(bloomDay[i],maxi);
        }
        int low=1;
        int high=maxi;
        int mid=0;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            int bloom=0;
            int nobloom=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    bloom++;
                    if(bloom==k){
                        nobloom++;
                        bloom=0;
                    }
                }
                else{
                    bloom=0;
                }
            }
            if(nobloom>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};

