//A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.
//Given a valid parentheses string s, your task is to remove the outermost parentheses from every primitive component of s and return the resulting
//Initialize an empty result string to store the processed output
//Initialize a counter (level) to track the depth of parentheses
//Traverse through the string character by character:
//If the current character is '(', increment the level counter. If the level is greater than 1 (indicating we're inside a valid primitive), add '(' to the result string
//If the current character is ')', decrement the level counter. If the level is greater than 0 (indicating we're still inside a valid primitive), add ')' to the result string
//After the entire string has been traversed, return the result string
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size();
        string ans;
        int level=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                level++;
                if(level>1){
                    ans+='(';
                }
            }
            else if(s[i]==')'){
                level--;
                if(level>0){
                    ans+=')';
                }
            }
        }
        return ans;
    }
};