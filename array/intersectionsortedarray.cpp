// intersection of two sorted arrays using two pointer logic
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

