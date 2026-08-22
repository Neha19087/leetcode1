class Solution {
public:
    string prefixToInfix(string s) {
        int i=s.size()-1;
        stack<string>st;
        while(i>=0){
            string c(1,s[i]);
            if((s[i]>='a'&& s[i]<='z')||( s[i]>='0' && s[i]<='9')){
                st.push(c);
            }
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string res= "("+t1+c+t2+")";
                st.push(res);
            }
            i--;
        }
        return st.top();
    }
};