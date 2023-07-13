// GREAT PROBLEM ON PARTITION IN ARRAY USING RECURSION
// USING FAITH HELPS A LOT IN SUCH PROBLEMS



class Solution {
public:
    int dp[501];

    int solve(vector<int>&arr,int k,int idx){
        if(idx==arr.size()){
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int ans=INT_MIN;
        int mv=INT_MIN;
        for(int i = idx;i<idx+k && i<arr.size();i++){
            mv = max(mv,arr[i]);
            ans = max(ans, mv*(i-idx+1) + solve(arr,k,i+1));
        }
        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,k,0);
    }
};
