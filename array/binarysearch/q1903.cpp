class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int right=n-1;
        while(right>=0){
            int last= num[right];
            if(last%2==0){
                right--;
            }
            else{
                break;
            }
        }
        if (right==-1) return "";
        string s(num.begin(),num.begin()+right+1);
        return s;
    }
};