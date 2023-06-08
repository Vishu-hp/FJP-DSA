// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    // PRINTINTG Longest Increasing Subsequence 
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tab(n,1), hash(n);
        int ans=1;
        int lastIndex=0;
        for(int i=0;i<n;i++){
            if(i==0){
                tab[i] = 1;
                hash[i]=i;
            }
            else{
                hash[i]=i;
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j] && tab[j]+1>tab[i]){
                        tab[i] = 1+tab[j];
                        hash[i] = j;
                    }
                }
            }
            
            if(tab[i] > ans){
                ans = tab[i];
                lastIndex = i;
            }
        }


        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(), temp.end());
        for(auto x:temp){
            cout<<x<<" ";
        }
        return ans;
    }
};
