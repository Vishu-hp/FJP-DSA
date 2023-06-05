// GFG SOLUTION
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    long long mod=1000000007;
    
    long long solve(int n,long long dp[]){
        if(n==0 || n==1){
            return 1;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long a1=solve(i-1,dp)%mod;
            long long a2 = solve(n-i,dp)%mod;
            ans += (a1*a2)%mod;
        }
        
        dp[n] = ans%mod;
        return ans%mod;
    }
    
    int numTrees(int N) 
    {
        // Your code here
        long long dp[10001]={0};
        return solve(N,dp);
    }
};

// LEETCODE SOLUTION
class Solution {
public:
    int numTrees(int n) {
        if(n<2){
            return 1;
        }
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
