// we have to find all elements where 
//0<=i<j<n   nums[i]>nums[j]
// brute force method will be to use 2 nested loops and check for each i its following indexs
// that fulfill the condition
// optimal solution is a kind of addition in merge sort
// that is after dividing the array in  sorted subarrays we will compare each element 
// of left subarray with right subarray 
// if that right array element is smaller than left array element than that element will be 
//smaller than all elements in left subarray following left element as arrays are sorted
// this will return all pairs as merge sort divides till single element
// and relative index of elements of arrays to each other is preserved as left array elements occur 
// before all right array elements always
//time complexity will be same as merge sort i.e. O(nlogn)
#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count inversions
int merge(vector<int> &arr, int low, int mid, int high) {
    // Temporary array to store merged elements
    vector<int> temp;

    // Starting index of left half
    int left = low;
    // Starting index of right half
    int right = mid + 1;

    // Variable to count inversions
    int cnt = 0;

    // Merge elements in sorted order and count inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // All remaining left elements are inversions
            right++;
        }
    }

    // If left half still has elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return inversion count
    return cnt;
}

// Merge sort function that counts inversions
int mergeSort(vector<int> &arr, int low, int high) {
    // Variable to store inversion count
    int cnt = 0;

    // Base case
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left half
    cnt += mergeSort(arr, low, mid);
    // Count inversions in right half
    cnt += mergeSort(arr, mid + 1, high);
    // Count inversions during merge
    cnt += merge(arr, low, mid, high);

    return cnt;
}

// Function to get number of inversions
int numberOfInversions(vector<int>& a, int n) {
    return mergeSort(a, 0, n - 1);
}


// this method can also be used to count pairs
//0<=i<j<n   nums[i]>2*nums[j] with a little spinoff
// exact logic cant be used as assume arr[left]< arr[right]
// then right element will be pushed in the array and right counter will move forward 
// but it is possible that condition was satisfied by an next element of left subarray with given j
// this was not a problem above because we checked only nums[i]>nums[j] and if nums[i] 
//was smaller than it will be pushed in the array and left pointer will move forward

class Solution {
public:
    void merge(int arr[],int low,int mid , int high){
        vector<int>merged;
        int left=low;
        int right= mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                merged.push_back(arr[left]);
                left++;
            }
            else{
                merged.push_back(arr[right]);
                right++;
                
            }
        }
        while(left<=mid){
            merged.push_back(arr[left]);
                left++;
        }
        while(right<=high){
            merged.push_back(arr[right]);
                right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=merged[i-low];
        }
    }
    int countpair(int arr[],int low,int mid, int high){
        int cnt=0;
        int left=low;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high &&(long long) arr[i]>2LL*arr[right]){
                right++;
            }
            cnt+=right-mid-1;
            
        }
        return cnt;
    }
    int merge_sort(int arr[],int low,int high){
        int cnt=0;
        int mid= (low+high)/2;
        if (low>=high) {
            return cnt;
        }
        cnt+=merge_sort(arr,low,mid);
        cnt+=merge_sort(arr,mid+1,high);
        cnt+=countpair(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        int cnt= merge_sort(nums.data(),0,n-1);
        return cnt;
    }
};