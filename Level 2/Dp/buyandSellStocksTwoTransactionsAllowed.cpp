// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(vector<int>&prices,int idx,int buy,int k,vector<vector<vector<int>>>&memo){
    //     if(idx==prices.size() || k==0){
    //         return 0;
    //     }

    //     if(memo[idx][buy][k] != -1){
    //         return memo[idx][buy][k];
    //     }

    //     int pro=0;
    //     if(buy){
    //         int a1 = solve(prices, idx+1, 0,k,memo) + (-prices[idx]);
    //         int a2 = solve(prices, idx+1, 1,k,memo);
    //         pro = max(a1, a2);
    //     }
    //     else{
    //         int a1 = solve(prices, idx+1, 1,k-1,memo) + (prices[idx]);
    //         int a2 = solve(prices, idx+1, 0,k,memo);
    //         pro = max(a1, a2);
    //     }
    //     return memo[idx][buy][k] = pro;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>>memo(n,vector<vector<int>>(2, vector<int>(3,-1)));
    //     return solve(prices, 0, 1, 2, memo);
    // }

    // TABULATION
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>>tab(n+1,vector<vector<int>>(2, vector<int>(3,0)));

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){
    //             for(int k=1;k<=2;k++){
    //                 int pro=0;
    //                 if(j){
    //                     int a1 = tab[i+1][0][k] + (-prices[i]);
    //                     int a2 = tab[i+1][1][k];
    //                     pro = max(a1, a2);
    //                 }
    //                 else{
    //                     int a1 = tab[i+1][1][k-1] + (prices[i]);
    //                     int a2 = tab[i+1][0][k];
    //                     pro = max(a1, a2);
    //                 }
    //                 tab[i][j][k] = pro;
    //             }
    //         }
    //     }

    //     return tab[0][1][2];
    // }

    // SPACE OPTIMIZATION
    //  int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>>next(2, vector<int>(3,0));
    //     vector<vector<int>>curr(2, vector<int>(3,0));

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){
    //             for(int k=1;k<=2;k++){
    //                 int pro=0;
    //                 if(j){
    //                     int a1 = next[0][k] + (-prices[i]);
    //                     int a2 = next[1][k];
    //                     pro = max(a1, a2);
    //                 }
    //                 else{
    //                     int a1 = next[1][k-1] + (prices[i]);
    //                     int a2 = next[0][k];
    //                     pro = max(a1, a2);
    //                 }
    //                 curr[j][k] = pro;
    //             }
    //         }
    //         next = curr;
    //     }

    //     return next[1][2];
    // }

    // MISC SOLUTION
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int>dp1(n,0);
        int leastVal=prices[0];
        int mp = 0;
        for(int i=1;i<n;i++){
            if(leastVal > prices[i]){
                leastVal = prices[i];
            }

            mp = prices[i] - leastVal;

            if(mp> dp1[i-1]){
                dp1[i] = mp;
            }
            else{
                dp1[i] = dp1[i-1];
            }
        }

        vector<int>dp2(n,0);
        int maxVal=prices[n-1];
        int mp2=0;
        for(int i=n-2;i>=0;i--){
            if(maxVal < prices[i]){
                maxVal = prices[i];
            }

            mp2 = maxVal - prices[i];

            if(mp2 > dp2[i+1]){
                dp2[i] = mp2;
            }
            else{
                dp2[i] = dp2[i+1];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(ans < dp1[i]+dp2[i]){
                ans = dp1[i]+dp2[i];
            }
        }
        return ans;
    }
};
