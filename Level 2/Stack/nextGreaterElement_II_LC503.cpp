class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n);
        
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.top()<=nums[i]){
                st.pop();
            }
            st.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top()<=nums[i]){
                st.pop();
            }
            
            if(st.size() == 0){
                ans[i]  = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
