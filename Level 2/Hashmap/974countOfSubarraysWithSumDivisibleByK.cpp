class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int>fr;
        fr[0] = 1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem<0){
                rem += k;
            }
            if(fr.count(rem)>0){
                ans += fr[rem];
                fr[rem]++;
            }
            else{
                fr[rem] = 1;
            }
        }
        return ans;
    }
};
