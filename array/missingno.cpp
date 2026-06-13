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
// take sum of first n elements and subtract sum of array from it
// you will get missing no
// take xor of elements of array with first n numbers 
//xor of x and x is 0 therefore cancelling all other elements leaving only missing element

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int xor1=0;
        int xor2=0;
        for(int i=0;i<n;i++){
            xor1= xor1^nums[i];
            xor2= xor2^(i+1);
        }
        return xor1^xor2;
    }
};

// now a no is missing and another no is repeating
// bruteforce method will be to iterate whole array and get the count of each element
// better method will be to store the count in a hasharray 
// there are 2 optimal solution
// one using mathematics
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // x= missing no   y= repeating no
        int n= nums.size();
        long long S=0;   //S= sum of elements of array =  Sn-x+y
        long long S2=0;   // S2= sum of squares of elements of array = Sn2-x^2+ y^2
        long long Sn=0;   //Sn= sum of first n elements
        long long Sn2=0;   // Sn2= sum of square of first n elements
        for(int i=0;i<n;i++){
            S+= nums[i];
            S2+= nums[i]*nums[i];
            Sn+= i+1;
            Sn2+= (i+1)*(i+1);
        }
        long long val1= Sn-S;  // (x-y)
        long long val2= Sn2-S2; // (x^2-y^2)
        long long val3= val2/val1;   // (y+x)
        int x= (val1+val3)/2;
        int y= val3-x;
        return {y,x};      
    }
};

// other is using xor and bit manipulation
// taking xor of all elements of the array with first n natural no will give xor of missing no 
// and repeating no
// use bit manipulation to find first non zero bit
// this bit would have been different in missing no and repeating no to give 1 after xor
// now we will differentiate all elements of array and first n elements depending on whether 
// there that element is 0 or 1
// now only repeating and missing no are odd no of times , all other are even times
// and both are in different groups
//take xor of each group and one will give missing and another repeating element
// check the count of these elements to know which is which
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // size of the array
        int n = nums.size(); 

        int xr = 0;

        for (int i = 0; i < n; i++) {
            // XOR of all elements in nums
            xr = xr ^ nums[i]; 
            
            // XOR of numbers from 1 to n
            xr = xr ^ (i + 1);  
        }

        // Get the rightmost set bit in xr
        int number = (xr & ~(xr - 1));

        //Group the numbers based on the differentiating bit
        // Number that falls into the 0 group
        int zero = 0; 
        
        // Number that falls into the 1 group
        int one = 0;  

        for (int i = 0; i < n; i++) {
            
            /* Check if nums[i] belongs to the 1 group
            based on the differentiating bit*/
            if ((nums[i] & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ nums[i];
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ nums[i]; 
            }
        }

        // Group numbers from 1 to n based on differentiating bit
        for (int i = 1; i <= n; i++) {
            
            /* Check if i belongs to the 1 group 
            based on the differentiating bit*/
            if ((i & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ i; 
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ i; 
            }
        }

        // Count occurrences of zero in nums
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (nums[i] == zero) {
                cnt++;
            }
        }

        if (cnt == 2) {
            /*zero is the repeating number,
            one is the missing number*/
            return {zero, one}; 
        }
        
        /* one is the repeating number, 
        zero is the missing number*/
        return {one, zero}; 
    }
};


