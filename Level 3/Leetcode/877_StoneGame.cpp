// GOOD DP PROBLEM. UNDERSTANDING HOW STATES FORM HERE IS IMPORTANT.WE ASSUME BOB WILL GIVE HIS MINIMUM POSSIBLE.

class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&arr,int i,int j){
        if(i==j){
            return arr[i];
        }

        if(i>j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int a1 = arr[i] + min(solve(arr,i+2,j), solve(arr,i+1,j-1));
        int a2 = arr[j] + min(solve(arr,i+1,j-1), solve(arr,i,j-2));
        return dp[i][j] = max(a1, a2);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int val = solve(piles,0,piles.size()-1);
        cout<<val<<endl;
        int sum=0;
        for(auto x:piles){
            sum+=x;
        }
        if(val > sum-val){
            return true;
        }
        return false;
    }
};
