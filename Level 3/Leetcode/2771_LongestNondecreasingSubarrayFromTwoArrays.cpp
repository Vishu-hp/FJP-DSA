// AMAZING AMAZING PROBLEM. GREAT FOR UNDERSTANDING RECURSION BASED ON CHOICES.HERE WE HAVE CHOICE FROM MULTIPLE ARRAYS.
// SOLVE AGAIN AGAIN .

class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2,int idx,int prev,
    vector<vector<int>>&dp){
        if(idx == nums1.size()){
            return 0;
        }

        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }

        int ans=0;
        if(prev == -1){
            int a1 = 1+solve(nums1,nums2,idx+1,0,dp);
            int a2 = 1+solve(nums1,nums2,idx+1,1,dp);
            int a3 = solve(nums1,nums2,idx+1,-1,dp);

            ans = max({a1,a2,a3});
        }
        else{
            int val=0;
            if(prev == 0){
                val = nums1[idx-1];
            }
            else{
                val = nums2[idx-1];
            }

            int a1=0, a2=0;
            if(nums1[idx]>=val){
                a1 = 1 + solve(nums1,nums2,idx+1,0,dp);
            }

            if(nums2[idx]>=val){
                a2 = 1 + solve(nums1,nums2,idx+1,1,dp);
            }

            ans = max(a1,a2);
        }
        return dp[idx][prev+1] = ans;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(3,-1));
        return solve(nums1,nums2,0,-1,dp);   
    }
};
