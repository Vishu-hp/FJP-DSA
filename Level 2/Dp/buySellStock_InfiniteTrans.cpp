// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(vector<int>&prices,int idx,int buy,vector<vector<int>>&memo){
    //     if(idx == prices.size()){
    //         return 0;
    //     }

    //     if(memo[idx][buy] != -1){
    //         return memo[idx][buy];
    //     }

    //     int pro = 0;
    //     if(buy){
    //         int a1 = solve(prices, idx+1 ,0,memo) + (-prices[idx]);
    //         int a2 = solve(prices, idx+1 ,1,memo);
    //         pro = max(a1, a2);
    //     }
    //     else{
    //         int a1 = solve(prices,idx+1,1,memo) + prices[idx];
    //         int a2 = solve(prices, idx+1,0,memo);

    //         pro = max(a1,a2);
    //     }

    //     return memo[idx][buy] = pro;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>>memo(n,vector<int>(2,-1));
    //     return solve(prices, 0, 1, memo);
    // }

    // TABULATION
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>>tab(n+1,vector<int>(2,-1));
        
    //     tab[n][0]=0;
    //     tab[n][1] =0;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){
    //             int pro=0;
    //             if(j){
    //                 int a1 =tab[i+1][0] + (-prices[i]);
    //                 int a2 = tab[i+1][1];
    //                 pro = max(a1, a2);
    //             }
    //             else{
    //                 int a1 = tab[i+1][1] + prices[i];
    //                 int a2 = tab[i+1][0];

    //                 pro = max(a1,a2);
    //             }
    //             tab[i][j] = pro;
    //         }
    //     }
    //     return tab[0][1];
    // }

    // SPACE OPTIMIZATION
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<int>next(2,-1), curr(2,-1);
        
    //     next[0]=0;
    //     next[1] =0;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){
    //             int pro=0;
    //             if(j){
    //                 int a1 =next[0] + (-prices[i]);
    //                 int a2 = next[1];
    //                 pro = max(a1, a2);
    //             }
    //             else{
    //                 int a1 = next[1] + prices[i];
    //                 int a2 = next[0];

    //                 pro = max(a1,a2);
    //             }
    //             curr[j] = pro;
    //         }
    //         next = curr;
    //     }
    //     return curr[1];
    // }

    // BEST SOLUTION
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP=0;
        int ps=prices[0] , pb = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                ps = prices[i];
            }
            else if(prices[i] < prices[i-1]){
                maxP += ps-pb;
                ps = prices[i];
                pb = prices[i];
            }
        }
        if(ps>pb){
            maxP += ps-pb;
        }
        return maxP;
    }
};
