#include <bits/stdc++.h>
using namespace std;
// first solution is brute force using a set to union two sorted arrays 
//without duplicates
// second solution is optimal where we directly insert elements in a array using
// two pointer logic

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        vector<int>arr;
        int i=0;
        int j=0;
        int index=0;
        int n= nums1.size();
        int m= nums2.size();
        while(i<n && j<m){
            if (nums1[i]<= nums2[j]){
                s.insert(nums1[i]); 
                i++;
            }
            else{
                s.insert(nums2[j]);
                j++;
            }
        }
        while(i<n){
            s.insert(nums1[i]);
            i++;
        }
        while(j<m){
            s.insert(nums2[j]);
            j++;
        }
        for (auto it:s){
            arr.push_back(it);
        }
        return arr;
    }
};

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int i=0;
        int j=0;
        vector<int>unionarr;
        while(i<n && j<m){
            if (nums1[i]<= nums2[j]){
                if (unionarr.size()==0|| unionarr.back()!= nums1[i]){
                    unionarr.push_back(nums1[i]);
                }
                i++;
            }
            else{
                if (unionarr.size()==0|| unionarr.back()!= nums2[j]){
                    unionarr.push_back(nums2[j]);
                }
                j++;
            }
        }
        while(i<n){
            if(unionarr.size()==0||unionarr.back()!= nums1[i]){
                unionarr.push_back(nums1[i]);
            }
            i++;
        }
        while(j<m){
            if (unionarr.size()==0|| unionarr.back()!= nums2[j]){
                    unionarr.push_back(nums2[j]);
                }
                j++;
        }
        return unionarr;
    }