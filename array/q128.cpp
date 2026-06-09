//we have to find the longest consecutive subsequence of elements of an array
// brute force method will be to iterate the array and for each element iterate the array to find its consecutive
// nos till there s no consecutive and update the max count each time

// better method will be to sort the array first and for every next element check if it is consecutive to previous 
// element while updating the max count at each step 
// if not then start a new subsequence from that element and start the counter from 1
// if element is equal to previous than just move to next element without incrementing the counter
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int cnt=0;
        int max_cnt=1;
        int smaller= INT_MIN;
        for (int i=0;i<n;i++){
            if(nums[i]-1==smaller){
                cnt++;
                smaller=nums[i];
            }
            else if(nums[i]!=smaller){
                cnt=1;
                smaller=nums[i];
            }
            max_cnt=max(cnt,max_cnt);

        }
        return max_cnt;
        
    }
};

// optimal solution will be to store all the elements of the array in an unordered set and and iterate through it
// for every element check if it can be the start of new subsequence by finding for its predecessor
// if predecessor exists it cant be the start of a consecutive subsequence so leave it
// if not then iterate the set to find all its consecutive elements
// as find operation of unordered set is usually of O(1), time complexity will be linear
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int max_cnt=0;  
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for (auto it:st){
            if(st.find(it-1)==st.end()){
                cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
            max_cnt= max(cnt,max_cnt);
            }
        }
        return max_cnt;
    }
}; 