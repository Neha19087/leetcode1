// we can find the square root of x using binary search in time complexity O(logn)
// use binary search when search space is limited and you are confirm to find the solution in a given range only
// brute metod is to use a loop from 1 to x, and updating each time i*i <=x
class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int low=1;
        int high=x;
        long mid=0;
        while(low<=high){
            mid= low +(high-low)/2;
            if(mid<=x/mid){                // if mid*mid<=x better solution can be on the right of mid
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;              // if mid*mid>x better solution will be on left 
            }
        }
        return ans;
        
    }
};