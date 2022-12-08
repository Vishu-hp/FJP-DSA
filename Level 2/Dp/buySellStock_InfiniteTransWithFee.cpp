// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int  n = prices.size();

        int obsp = -prices[0];
        int ossp = 0 ;

        for(int i=1;i<n;i++){
            int nbsp,nssp;

            if(ossp - prices[i] > obsp){
                nbsp = ossp - prices[i];
            }
            else{
                nbsp = obsp;
            }

            if(obsp+prices[i]-fee > ossp){
                nssp = obsp + prices[i]-fee;
            }
            else{
                nssp = ossp;
            }

            obsp = nbsp;
            ossp = nssp;
        }
        return ossp;
    }
};
