// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
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
