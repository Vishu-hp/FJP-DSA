class Solution {
public:
    vector<int>nge(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n);
        ans[n-1] = -1;
        stack<int>st;
        st.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(st.top() > nums[i]){
                ans[i] = st.top();
                st.push(nums[i]);
            }
            else{
                while(st.size()>0 && st.top() <= nums[i]){
                    st.pop();
                }

                if(st.size()==0){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }
                st.push(nums[i]);
            }
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>h1 = nge(nums2);
        unordered_map<int, int>ump;
        for(int i=0;i<h1.size();i++){
            ump[nums2[i]] = h1[i];
        }

        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = ump[nums1[i]];
        }
        return ans;
    }
};
