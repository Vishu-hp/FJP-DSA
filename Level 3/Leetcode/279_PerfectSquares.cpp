// GOOD DP PROBLEM.START FROM 1 AND DO TAKE OR SKIP RECURSIVELY

class Solution {
public:
    int dp[10001][101];
    int solve(int n,int num){
        if(n==0){
            return 0;
        }

        if(n<0 || num*num > n){
            return INT_MAX;
        }

        if(dp[n][num] !=-1){
            return dp[n][num];
        }

        int a1 = solve(n,num+1);
        int a2 = solve(n - num*num, num);
        if(a2 != INT_MAX){
            a2=a2+1;
        }
        return dp[n][num] = min(a1,a2);
    }

    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1);
    }
};
