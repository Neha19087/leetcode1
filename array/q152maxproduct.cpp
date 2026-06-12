// we have to find the subarray that has maximum product and return the product
// brute force will be to find every subarray using 2 nested loops and finding the max product
// optimal method will be to accept that there are negatives in the array and calculate product
// around them by maintaining two pointers , one to calculate product from start and other from ending
// time complexity will be O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int max_product=INT_MIN; 
        int prefix=1;
        int suffix=1;
        for(int i=0;i<n;i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix*=nums[i];
            suffix*=nums[n-1-i];
            max_product=max(max_product,max(prefix,suffix));
        }
            
        return max_product;
    }
};  