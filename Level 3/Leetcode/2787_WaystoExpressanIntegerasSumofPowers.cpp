// GOOD DP PROBLEM.START FROM 1 AND DO TAKE OR SKIP RECURSIVELY

class Solution {
public:
    const int mod = 1e9+7;
    int dp[301][301];

    int solve(int n,int num,int x){
        if(n == 0){
            return 1;
        }

        if(n<0 || pow(num,x) > n){
            return 0;
        }

        if(dp[n][num] != -1){
            return dp[n][num];
        }

        int a1 = solve(n,num+1,x)%mod;
        int a2 = solve(n - pow(num,x),num+1,x)%mod;
        return dp[n][num] = (a1+a2)%mod;
    }

    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1,x);
    }
};
