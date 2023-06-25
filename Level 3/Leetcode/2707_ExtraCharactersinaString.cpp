// GOOD STRING + DP PROBLEM

class Solution {
public:
    int dp[51];
    int solve(string s,int idx,vector<string>&d){
        if(idx == s.length()){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int ans = INT_MAX;
        for(int i=1;i<=s.length()-idx;i++){
            string ss = s.substr(idx,i);
            if(find(d.begin(),d.end(),ss) != d.end()){
                ans = min(ans,solve(s,idx+i,d));
            }
        }
        
        ans = min(ans, 1 + solve(s,idx+1,d));
        return dp[idx] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,dictionary);
    }
};
