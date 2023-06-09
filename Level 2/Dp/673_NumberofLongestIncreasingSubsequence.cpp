class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        int maxl=1,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp1[j]+1>dp1[i]){
                    dp1[i] = 1+dp1[j];
                    dp2[i] = dp2[j];
                }
                else if(nums[i]>nums[j] && dp1[j]+1 == dp1[i]){
                    dp2[i] += dp2[j];
                }
            }
            if(dp1[i] > maxl){
                maxl = dp1[i];
            }
        }

        for(int i=0;i<n;i++){
            if(dp1[i] == maxl){
                cnt += dp2[i];
            }
        }
        return cnt;
    }
};
