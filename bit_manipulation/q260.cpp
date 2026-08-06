class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long xori=0;
        for(int i=0;i<n;i++){
            xori=xori^nums[i];
        }
        int rightmost= (xori &(xori-1))^xori;
        int b1=0;
        int b2=0;
        for(int i=0;i<n;i++){
            if((nums[i] & rightmost) !=0){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
        
    }
};