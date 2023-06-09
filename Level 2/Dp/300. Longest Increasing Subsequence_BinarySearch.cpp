class Solution {
public:
    // USING BINARY SEARCH
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int>tmp;
        tmp.push_back(nums[0]);
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i] > tmp.back()){
                tmp.push_back(nums[i]);
                ans++;
            }
            else{
                int idx = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                tmp[idx] = nums[i]; 
            }
        }
        return ans;
    }
};
