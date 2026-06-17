//Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
//If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//Return the minimum integer k such that she can eat all the bananas within h hours.

// brute force method will be to initialize k from 1 and run a while loop icrementing k by 1 each time till all bananas can be eaten in desired time
//it wiil take time O(k*n)

//here binary search can also be used as we know for sure that our answer will lie in range 1 to max. bananas on a tree as any no greater than that 
//will always give n (size of array or no of trees as answer )
// time complexity will be O(nlogm)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);   
        }  
        int low=1;
        int high=maxi;
        int mid=0;
        int ans=0;
        while(low<=high){
            mid=(low+high)/2;
            long long hours=0;
            long long rem=0;
            for(int i=0;i<n;i++){
                if (piles[i]%mid==0) rem= piles[i]/mid;
                else rem= (piles[i]/mid) +1;
                hours+=rem;
            }
            if(hours==h){ 
                ans=mid;
                high=mid-1;
            }
            else if(hours>h){
                low=mid+1;
            }
            else{
                high= mid-1;
                ans=mid;
            }
        }  
        return ans; 
    }
};
 
//similar question will be Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, 
//divide all the array by it, and sum the division's result. 
//Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
//Each result of the division is rounded to the nearest integer greater than or equal to that element. 
//(For example: 7/3 = 3 and 10/2 = 5).
//The test cases are generated so that there will be an answer.

// here also the range of answer is fixed from 1 to max element of the array
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        int low=1;
        int high=maxi;
        int mid=0;
        int ans=0;
        while(low<=high){
            mid=(low+high)/2;
            int rem=0;
            for(int i=0;i<n;i++){
                int div=0;
                if (nums[i]%mid==0){
                    div= nums[i]/mid;
                }
                else{
                    div= nums[i]/mid +1;
                }
                rem+=div;
            }
            if(rem<=threshold){
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