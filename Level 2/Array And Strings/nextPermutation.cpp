// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return;
        }
        
        if(n==2){
            if(nums[0]>nums[1]){
                sort(nums.begin(),nums.end());
            }
            else{
                int tmp = nums[0];
                nums[0] = nums[1];
                nums[1] = tmp;
            }
            return;
        }
        int idx1=-1,idx2;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx1 = i;
                break;
            }
        }
        
        if(idx1==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>idx1;i--){
            if(nums[i]>nums[idx1]){
                idx2 = i;
                break;
            }
        }
        
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
        
        int l = idx1+1;
        int r = n-1;
        while(l<r){
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
        return;
    }
};
