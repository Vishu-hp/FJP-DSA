// DP WITH BITMASK PRACTICE PROBLEM

class Solution {
public:
    int  dp[(1<<16)][16]; 

    int solve(int mask,int idx,int n){
        if(idx>n){
            return 1;
        }

        if(dp[mask][idx] !=- 1){
            return dp[mask][idx];
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(((1<<i) & mask) > 0){
                continue;
            }

            if(i%idx==0 || idx%i==0){
                ans += solve(mask | (1<<i), idx+1,n);
            }
        }
        return dp[mask][idx] = ans;
    }

    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,n);
    }
};
