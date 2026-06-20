// we have to return the kth element from two sorted arrays 
//brute method will be to merge both arrays and then return the kth element
// better method will be to track the count instead of actually storing the merged array 
//and return kth element
// time complexity will be sum of size of both arrays
//optimal method will be to use binary search
// we can take the smaller array and virtually divide the merged array into two parts
//one part with k elements and other with (n1+n2+k) elements
//using binary search we can determine how many elements from this smaller array should be taken in 
//these k elements
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1= a.size();
        int n2= b.size();
        if (n1>n2) return kthElement(b,a,k);
        int low= max(0,k-n2);             //atleast these many should be taken 
        int high= min(n1,k);             // max these many can be taken
        int mid1=0;
        int mid2=0;
        int left=k;
        int l1= INT_MIN;
        int l2= INT_MIN;
        int r1= INT_MAX;
        int r2= INT_MAX;
        while(low<=high){
            mid1=(low+high)/2;
            mid2=left-mid1;
            if(mid1<n1) r1= a[mid1];
            if(mid2<n2) r2= b[mid2];
            if(mid1>0) l1=a[mid1-1];
            if(mid2>0) l2=b[mid2-1];
            if(l1>r2){
                high=mid1-1;
            }
            else if(l2>r1){
                low=mid1+1;
            }
            else{
                return max(l1,l2);
            }


        }
        return 0;
    }
};