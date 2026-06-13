// intersection of two sorted arrays using two pointer logic
// brute code for given question will be if iterate any one array and iterate 
// array by each element to find if guven element is there or not 
#include <bits/stdc++.h>
using namespace std;
vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size();
    int m= nums2.size();
    vector<int>intersectionarr;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if (nums1[i]==nums2[j]){
            intersectionarr.push_back(nums1[i]);
            i++;
            j++;
        }
        if (nums1[i]< nums2[j]){
            i++;
        }
        else {
            j++;
        }
    }
    return intersectionarr;
    
}
// use this code instead if you want duplicate elements also

vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size();
    int m= nums2.size();
    vector<int>intersectionarr;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if (nums1[i]< nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]) {
            j++;
        }
        
        else{
            intersectionarr.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return intersectionarr;
    
}

int main() {
    vector<int>nums1;
    vector<int>nums2;
    vector<int>nums3;
    int n;
    cin>>n;
    int n1;
    int n2;
    for ( int i=0; i<n;i++){
        cin>>n1;
        nums1.push_back(n1);
    }
    int m;
    cin>>m;
    for ( int i=0; i<m;i++){
        cin>>n2;
        nums2.push_back(n2);
    }
    nums3= intersectionArray(nums1, nums2);
    int n3;
    n3= nums3.size();
    for (int i=0; i<n3; i++){
        cout<< nums3[i]<<" ";
    }
}


// to get intersection of two unsorted array we can store the elements of one array in a hashmap and then compare directly
// this code returns elements in intersection array only once even if they appear multiple times in both arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        vector<int>arr;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<m;i++){
            if (mpp.find(nums2[i])!=mpp.end() && mpp[nums2[i]]>0){
                arr.push_back(nums2[i]);
                mpp[nums2[i]]=-1;
            }
        }
        return arr;
    }
};

// this slight modification will allow intersection array to contain duplicate elements
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        vector<int>arr;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<m;i++){
            if (mpp.find(nums2[i])!=mpp.end() && mpp[nums2[i]]>0){
                arr.push_back(nums2[i]);
                mpp[nums2[i]]--;
            }
        }
        return arr;
    }
};
