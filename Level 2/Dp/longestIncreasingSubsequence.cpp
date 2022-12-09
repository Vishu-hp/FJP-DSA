// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>dp(n,0);
       
       int ans=0;
       
       for(int i=0;i<n;i++){
           int maxV=0;
           
           for(int j=0;j<i;j++){
               if(a[i]>a[j]){
                   maxV = max(maxV,dp[j]);
               }
           }
           
           dp[i] = maxV + 1;
           
           ans=max(ans,dp[i]);
       }
       return ans;
    }
};
