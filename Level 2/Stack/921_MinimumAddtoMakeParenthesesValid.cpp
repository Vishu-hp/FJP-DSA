class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(s[i]=='('){
                st.push(ch);
            }
            else{
                if(st.size() > 0){
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
                else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};
