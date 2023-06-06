// https://leetcode.com/problems/house-robber/description/
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
public:
    // MEMOIZATION
    // int solve(int idx, vector<int>&nums, vector<int>&dp){
    //     if(idx>= nums.size()){
    //         return 0;
    //     }

    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }

    //     int a1 = solve(idx+1, nums, dp);
    //     int a2 = nums[idx] + solve(idx+2, nums, dp);
    //     return dp[idx] = max(a1, a2);
    // }

    // int rob(vector<int>& nums) {
    //    vector<int>dp(nums.size(),-1);
    //    return solve(0,nums,dp);
    // }

    // TABULATION
    int rob(vector<int>& nums) {
       int n =nums.size();
       vector<int>inc(n,0);
       vector<int>exc(n,0);

       inc[0]=nums[0];
       exc[0]=0;
       for(int i=1;i<n;i++){
           inc[i] = nums[i]+exc[i-1];
           exc[i] = max(inc[i-1], exc[i-1]);
       }

       return max(inc[n-1], exc[n-1]);
    }


    // SPACE OPTIMIZED CODE
    // int rob(vector<int>& nums) {
    //     int loot = nums[0];
    //     int leave = 0;
        
    //     int ans=0;
    //     for(int i=1;i<nums.size();i++){
    //         int newloot = nums[i] + leave;
    //         int newleave = max(loot,leave);
            
    //         loot = newloot;
    //         leave = newleave;
    //     }
    //     return max(loot,leave);
    // }
};
