// GENERAL RECURSIVE WAY DOES NOT WORK 
// SO THIS DP + BITMASK IS A GOOD APPROACH

class Solution {
public:
    int dp[(1<<16)][16];
    bool solve(vector<int>&nums,int mask,int sst,int k,int ssf,int sss){
        if(sst == k){
            return true;
        }

        if(dp[mask][sst] != -1){
            return dp[mask][sst];
        }

        bool ans=false;
        for(int i=0;i<nums.size();i++){
            if(((1<<i) & mask) > 0){
                continue;
            }

            if(nums[i]+ssf > sss){
                continue;
            }

            if(nums[i]+ssf<sss){
                ans = ans || solve(nums,mask | (1<<i), sst, k, ssf+nums[i],sss);
            }
            else{
                ans  = ans || solve(nums, mask | (1<<i),sst+1,k,0,sss);
            }
        }

        return dp[mask][sst] = ans;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        if(sum%k != 0){
            return false;
        }

        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,k,0,sum/k);
    }
};
