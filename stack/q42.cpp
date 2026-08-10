class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> leftlarge;
        vector<int> rightlarge(n,0);
        int leftmax=0;
        int rightmax=0;
        for(int i=0;i<n;i++){
            leftlarge.push_back(leftmax);
            if(height[i]>leftmax){
                leftmax=height[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            rightlarge[i]=rightmax;
            if(height[i]>rightmax){
                rightmax=height[i];
            }
        }
        int total=0;
        for(int i=1;i<n-1;i++){
            if(min(leftlarge[i],rightlarge[i])>height[i]){
                total+=min(leftlarge[i],rightlarge[i])-height[i];
            }
        }
        return total;
    }
};