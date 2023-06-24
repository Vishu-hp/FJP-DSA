// GOOD HASHMAP IMPLEMENTATION PROBLEM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>ump;
        for(int x:nums){
            ump[x]=true;
        }

        for(int x:nums){
            if(ump.find(x-1)!=ump.end()){
                ump[x]=false;
            }
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(ump[nums[i]]){
                int l=1;
                int sp=nums[i];
                while(ump.find(sp+l) != ump.end()){
                    l++;
                }

                ans = max(ans,l);
            }
        }
        return ans;
    }
};
