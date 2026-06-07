// trying to find a missing no. from a range
// brute solution
//iterating the array n no of times
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        for(int i=0; i<=n; i++){
            int cnt=0;
            for (int j=0;j<n; j++){
                if (nums[j]==i){
                    cnt=1;
                }
            }
            if (cnt==0){
                return i;
                break;
            }
            
        }
        
    }
};

// better solution
//hash map

// optimal solution
//  sum and xor 