class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&memo){
        if(i>j){
            return 0;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int val=INT_MIN;
        for(int k=i;k<=j;k++){
            int v = solve(nums,i,k-1,memo)+solve(nums,k+1,j,memo) + nums[k]*nums[i-1]*nums[j+1];
            val = max(val, v);
        }

        return memo[i][j] = val;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return solve(nums,1,n,memo);   
    }
};
