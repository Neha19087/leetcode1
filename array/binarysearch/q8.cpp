//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
//The algorithm for myAtoi(string s) is as follows:
//Whitespace: Ignore any leading whitespace (" ").
//Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached.
// If no digits were read, then the result is 0.
//Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. 
//Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//Return the integer as the final result.
class Solution {
public:
    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;

    // Recursive helper
    int helper(const string &s, int i, long long num, int sign) {
        // If we are out of bounds or at a non-digit, return
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        // Update num with current digit
        num = num * 10 + (s[i] - '0');

        // Clamp if overflow
        if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
        if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

        // Recurse for next character
        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int i=0;
         while (i < s.size() && s[i] == ' ') i++;

        // Handle sign
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Call recursive helper
        return helper(s, i, 0, sign);
            
        
    }
};