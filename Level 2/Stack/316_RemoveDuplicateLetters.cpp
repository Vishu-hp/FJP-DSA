// Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int>count(26,0);
        for(int i=0;i<n;i++){
            count[s[i] - 'a']++;
        }

        vector<bool>vis(26,false);

        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            
            if(vis[ch - 'a']){
                count[ch - 'a']--;
                continue;
            }

            while(st.size()>0 && st.top() > ch && count[st.top() - 'a']>0){
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            vis[ch - 'a']=true;
            count[ch - 'a']--;
        }

        string ans="";
        while(st.size()>0){
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }
        return ans;
    }
};
