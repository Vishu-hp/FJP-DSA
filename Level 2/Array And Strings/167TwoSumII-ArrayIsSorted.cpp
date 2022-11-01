// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int l =0 , r= numbers.size()-1;
        
        while(l<r){
            int sum = numbers[l] + numbers[r];
            
            if(sum == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(sum<target){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
