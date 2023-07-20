// GOOD PROBLEM FOR KIND OF SLIDING WINDOW

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n= nums.size();
        multiset<int>m1,m2;

        for(int i=0;i<n;i++){
            m2.insert(nums[i]);
        }

        for(int i=0;i<n;i++){
            m1.insert(nums[i]);
            m2.erase(m2.find(nums[i]));

            if(*(m1.rbegin()) <= *(m2.begin())){
                return i+1;
            }
        }
        return n;
    }
};
