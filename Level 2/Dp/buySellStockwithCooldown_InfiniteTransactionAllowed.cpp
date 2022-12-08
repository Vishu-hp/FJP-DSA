// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int  bsp=-prices[0] , ssp=0,csp=0;
        for(int i=1;i<n;i++){
            int nbsp=0,nssp=0,ncsp=0;

            if(csp-prices[i] > bsp){
                nbsp = csp - prices[i];
            }
            else{
                nbsp = bsp;
            }

            if(bsp+prices[i] > ssp){
                nssp = bsp + prices[i];
            }
            else{
                nssp = ssp;
            }

            if(ssp > csp){
                ncsp = ssp;
            }
            else{
                ncsp = csp;
            }

            bsp = nbsp;
            ssp = nssp;
            csp = ncsp;
        }
        return ssp;
    }
};
