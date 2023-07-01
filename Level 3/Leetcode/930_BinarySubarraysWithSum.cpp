// GOOD PROBLEM ON SLIDING WINDOW. APPLICATION OF GETTING SUBARRAYS WITH SUM <= TARGET.
// INTUTION: DEALING WITH SUBARRAYS SO SLIDING WINDOW CAN COME TO MIND

class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n = nums.size();
        int cnt=0, sum=0;
        int i=0, j=0;
        while(j<n){
            sum += nums[j];

            while(i<=j && sum>k){
                sum -= nums[i];
                i++;
            }

            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a1 = solve(nums,goal);
        int a2 = solve(nums,goal-1);
        return a1-a2;
    }
};
