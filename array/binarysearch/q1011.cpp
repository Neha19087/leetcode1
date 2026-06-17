//A conveyor belt has packages that must be shipped from one port to another within days days.
//The ith package on the conveyor belt has a weight of weights[i]. 
//Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
//We may not load more weight than the maximum weight capacity of the ship.
//Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// brute force will be to run a while loop from 1 and icrementing it by one each time  and finding the min  weight capacity required to ship 
//all the packages within required days
// here binary search can be used as answer will always lie in the range max of array(should be delivered in 1 day) 
//and sum of array(if all packages are to be delivered in single day)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int maxi=0;
        int sumi=0;
        for(int i=0;i<n;i++){
            maxi=max(weights[i],maxi);
            sumi+=weights[i];
        }
        int low=maxi;
        int high=sumi;
        int mid=0;
        int ans=0;
        while(low<=high){
            mid=(low+high)/2;
            int sumwt=0;
            int nodays=0;
            for(int i=0;i<n;i++){
                sumwt+=weights[i];
                if(sumwt==mid){
                    nodays++;
                    sumwt=0;
                }
                else if(sumwt>mid){
                    nodays++;
                    sumwt=weights[i];
                }

            }
            if (sumwt>0) nodays= nodays+1;
            if(nodays<=days){
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