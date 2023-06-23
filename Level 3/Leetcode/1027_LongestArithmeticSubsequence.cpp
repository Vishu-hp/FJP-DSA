// PROBLEM IS NOT VERY INTUITIVE
// https://www.youtube.com/watch?v=Y3sZ2bsresI&ab_channel=RahulManghnani

// WORKING SOLUTION
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>>v(n);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];

                if(v[j].count(diff) > 0){
                    v[i][diff] = v[j][diff] + 1;
                }
                else{
                    v[i][diff] = 1;
                }

                ans = max(ans, v[i][diff]+1);
            }
        }
        return ans;
    }
};

// RECURSION + MEMOIZATION GIVES TLE
class Solution {
public:
    int dp[1005][1005];
    int solve(vector<int>&nums,int idx,int diff){
        if(idx == nums.size()){
            return 0;
        }

        if(dp[idx][diff+500]!=-1){
            return dp[idx][diff+500];
        }

        int ans=0;
        for(int i=idx+1;i<nums.size();i++){
            if(diff == nums[i]-nums[idx]){
                ans = 1+ solve(nums,i,diff);
                break;
            }
        }

        return dp[idx][diff+500] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, 2 + solve(nums,j,nums[j]-nums[i]));
            }
        }
        return ans;
    }
};
