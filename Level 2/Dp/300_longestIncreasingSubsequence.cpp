// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(vector<int>&nums,int idx,int pi, vector<vector<int>>&memo){
    //     if(idx == nums.size()){
    //         return 0;
    //     }

    //     if(memo[idx][pi+1] != -1){
    //         return memo[idx][pi+1];
    //     }

    //     if(pi==-1 || nums[idx]>nums[pi]){
    //         int a1 = solve(nums,idx+1,idx,memo)+1;
    //         int a2 = solve(nums,idx+1,pi,memo);
    //         return memo[idx][pi+1] = max(a1, a2);
    //     }
    //     else{
    //         return memo[idx][pi+1] = solve(nums,idx+1,pi,memo);
    //     }
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>memo(n,vector<int>(n+1,-1));
    //     return solve(nums, 0 ,-1,memo);
    // }

    // TABULATION
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>tab(n+1,vector<int>(n+1,0));

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i-1;j>=-1;j--){
    //             if(j==-1 || nums[i]>nums[j]){
    //                 int a1 = tab[i+1][i+1]+1;
    //                 int a2 = tab[i+1][j+1];
    //                 tab[i][j+1] = max(a1, a2);
    //             }
    //             else{
    //                 tab[i][j+1] = tab[i+1][j+1];
    //             }
    //         }
    //     }
    //     return tab[0][-1+1];
    // }

    // SPACE OPTIMIZATION
    //   int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>next(n+1,0), curr(n+1,0);

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i-1;j>=-1;j--){
    //             if(j==-1 || nums[i]>nums[j]){
    //                 int a1 = next[i+1]+1;
    //                 int a2 = next[j+1];
    //                 curr[j+1] = max(a1, a2);
    //             }
    //             else{
    //                 curr[j+1] = next[j+1];
    //             }
    //         }
    //         next=curr;
    //     }
    //     return curr[-1+1];
    // }

    // TABULATION - 1d
    
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>tab(n,-1);
    //     int ans=1;
    //     for(int i=0;i<n;i++){
    //         if(i==0){
    //             tab[i] = 1;
    //         }
    //         else{
    //             int mv=0;
    //             for(int j=0;j<i;j++){
    //                 if(nums[i]>nums[j]){
    //                     mv = max(mv, tab[j]);
    //                 }
    //             }
    //             tab[i] = 1 + mv;
    //         }
    //         ans = max(ans, tab[i]);
    //     }
    //     return ans;
    // }
};
