class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char>st;

        for(int i=0;i<n;i++){
            char ch = s[i];

            if(ch==')'){
                queue<char>q;
                while(st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();

                while(q.size()>0){
                    st.push(q.front());
                    q.pop();
                }
            }
            else{
                st.push(ch);
            }
        }

        string ans="";
        while(st.size() >0){
            char ch=st.top();
            st.pop();

            ans =  ch+ans;
        }
        return ans;
    }
};
