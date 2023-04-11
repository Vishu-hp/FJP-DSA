class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        
        unordered_map<int,int>fr;
        fr[0]=-1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            if(fr.count(sum)>0){
                ans = max(ans,i-fr[sum]);
            }
            else{
                fr[sum]=i;
            }
        }
        return ans;
    }
};
