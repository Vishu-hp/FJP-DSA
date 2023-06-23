// DP WITH BITMASK PRACTICE PROBLEM

class Solution {
public:
    int dp[(1<<21)][2];

    bool solve(int mask,int dt,int mci,int p){

        if(dp[mask][p] != -1){
            return dp[mask][p];
        }

        for(int i=1;i<=mci;i++){
            if(((1<<i) & mask) > 0){
                continue;
            }
            
            if(dt - i <=0){
                return true;
            }

            bool sa =  solve(mask | (1<<i),dt-i,mci,p^1);
            if(sa == false){
                return true;
            }
        }
        return dp[mask][p] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum=0;
        for(int i=1;i<=maxChoosableInteger;i++){
            sum += i;
        }

        if(sum< desiredTotal){
            return false;
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,desiredTotal,maxChoosableInteger,0);
    }
};
