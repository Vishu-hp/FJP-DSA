// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(k+1,vector<int>(n,0));

        for(int t=1;t<k+1;t++){
            int maxV = INT_MIN;

            for(int d=1;d<n;d++){
                if(dp[t-1][d-1] - prices[d-1] > maxV){
                    maxV = dp[t-1][d-1] - prices[d-1];
                }

                if(maxV + prices[d] > dp[t][d-1]){
                    dp[t][d] = maxV + prices[d];
                }
                else{
                    dp[t][d] = dp[t][d-1];
                }
            }
        }
        return dp[k][n-1];
    }
};
