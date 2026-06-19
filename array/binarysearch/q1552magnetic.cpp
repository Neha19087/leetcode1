//In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
//if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i],
// Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
//Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
//Given the integer array position and the integer m. Return the required force.
//we have to maximise the min distance between any two balls
//in such maximise the minimum and minimise the maximum problems we can use binary search on answer range 
// here distance can vary from 1 to max element - min element
// after setting a min distance we start placing balls such that they have  atleast that distance between them
// if no of balls placed is equal than or greater to required no than it can be the ans
// also we can try to increase this distance if they still satisfy the condition
// time complexity will be O(nlogm)
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n= position.size();
        sort(position.begin(),position.end());
        int maxi= position[n-1]-position[0];
        int low=1;
        int high=maxi;
        int ans=0;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            int diff=0;
            int start=position[0];
            int ballposition=1;
            for(int i=1;i<n;i++){
                diff= position[i]-start;
                if(diff>=mid){
                    start=position[i];
                    ballposition++;
                }
            }
            if(ballposition>=m){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

