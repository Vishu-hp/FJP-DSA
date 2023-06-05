class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i1=0,i2=0;
        int n = pushed.size();
        while(i1<n){
            st.push(pushed[i1]);
            i1++;

            while(st.size()>0 && st.top()==popped[i2]){
                st.pop();
                i2++;
            }
        }

        if(st.size()>0){
            return false;
        }
        return true;
    }
};
