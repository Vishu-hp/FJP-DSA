// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
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
