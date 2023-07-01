// GOOD PROBLEM ON RECURSION ON SUBARRAY AND DP

class Solution {
public:
    int dp[1001][51];

    int solve(vector<int>&nums,int idx,int k){
        if(idx == nums.size()){
            if(k==0){
                return 0;
            }
            return INT_MAX;
        }

        if(k<0){
            return INT_MAX;
        }

        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }

        int csum = 0;
        int ans = INT_MAX;
        for(int i=idx;i<nums.size();i++){
            csum += nums[i];

            int faith = solve(nums,i+1,k-1);
            ans = min(ans, max(csum, faith));
        }
        return dp[idx][k] = ans;
    }

    int splitArray(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,k);
    }
};
