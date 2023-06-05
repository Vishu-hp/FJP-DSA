// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c=='('){
                if(st.size() >0){
                    ans += c;
                }
                st.push(c);
            }
            else{
                st.pop();
                if(st.size()!=0){
                    ans += c;
                }
            }
        }
        return ans;
    }
};
