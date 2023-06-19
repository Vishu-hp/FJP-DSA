// You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

// For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
// Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.


class Solution {
public:
    int dp[(1<<15)][15];
    int mod = 1e9+7;
    int solve(vector<int>&nums,int mask,int idx,int pi){
        if(idx == nums.size()){
            return 1;
        }

        if(dp[mask][pi+1] != -1){
            return dp[mask][pi+1];
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(((1<<i)&mask) > 0){
                continue;
            }

            if(pi==-1 || nums[pi]%nums[i]==0 || nums[i]%nums[pi]==0){
                ans = (ans + solve(nums,mask | (1<<i),idx+1,i))%mod;
            }
        }
        return dp[mask][pi+1] = ans;
    }

    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,-1);
    }
};
