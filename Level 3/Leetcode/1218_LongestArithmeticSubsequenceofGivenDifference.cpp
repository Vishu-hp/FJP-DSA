// GREAT PROBLEM FOR APPLICATION OF RECURSION ON SUBSEQUENCE AND MEMOIZATION. ALTHOUGH IT GIVES TLE .
// THEN WE USE TABULATION IT IS ALSO IMPORTANT , WE CONSIDER STATE AS dp[arr[i]] as las ending at this element.THEN RECURRENCE AS WE CONSIDER LAS ENDING AT ARR[I]-DIFF.

class Solution {
public:
    // RECURSION + MEMOIZATION (TLE)
    // int solve(vector<int>&arr,int diff,int idx,int prev,vector<vector<int>>&dp){
    //     if(idx == arr.size()){
    //         return 0;
    //     }

    //     if(dp[idx][prev+1]!=-1){
    //         return dp[idx][prev+1];
    //     }

    //     int a1 = solve(arr,diff,idx+1,prev,dp);
    //     int a2=0;
    //     if(prev==-1 || arr[idx]-arr[prev] == diff){
    //         a2 = 1+solve(arr,diff,idx+1,idx,dp);
    //     }
    //     return dp[idx][prev+1] = max(a1,a2);
    // }

    // int longestSubsequence(vector<int>& arr, int difference) {
    //     int n = arr.size();
    //     int ans=0;
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return solve(arr,difference,0,-1,dp);
    // }

    // TABULATION
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans=1;

        unordered_map<int,int>dp;
        for(int i=0;i<n;i++){
            int num = arr[i];

            if(dp.count(num-difference) == 1){
                dp[num] = dp[num-difference] + 1;
            }
            else{
                dp[num]=1;
            }

            ans = max(ans, dp[num]);
        }
        return ans;
    }
};
