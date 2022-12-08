// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = prices[0];
        int maxP = 0;
        for(int i=1;i<n;i++){
            int p = max(0,prices[i]-minSoFar);
            maxP = max(maxP,p);
            minSoFar = min(minSoFar,prices[i]);
        }
        return maxP;
    }
};
