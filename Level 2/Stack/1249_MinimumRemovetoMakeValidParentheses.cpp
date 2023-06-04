class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch>='a' && ch<='z'){
                continue;
            }
            else{
                if(ch=='('){
                    st.push(i);
                }
                else{
                    if(st.size() == 0){
                        s[i]='.';
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }

        while(st.size()>0){
            s[st.top()]= '.';
            st.pop();
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};
