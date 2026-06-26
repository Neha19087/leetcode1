class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
        
    }
};
//this is brute force algorithm where we concatenate the string 2 times and check if our target exists in this new string 
// time complexity is O(n^2)
// another method is to simulate each rotation and check if it matches the goal
//time complexity will be same