// GOOD PROBLEM ON SLIDING WINDOW. WE NEED MAX AND MIN IN SUBARRAY SO WE USE MULTISET.WE CAN USE 2 MULTISETS FOR MAX AND MIN SEPARATELY,OR WE
// CAN USE ONLY 1 MULTISET FOR BOTH AS WE CAN USE END AND BEGIN.

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int>m1;

        int i=0,j=0,ans=0;
        while(j<n){
            m1.insert(nums[j]);

            while(i<=j && *(m1.rbegin()) - *(m1.begin()) > limit){
                m1.erase(m1.find(nums[i]));
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
