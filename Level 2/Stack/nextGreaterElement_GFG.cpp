// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>st;
        vector<long long>ans(n);
        ans[n-1]= -1;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(st.top() > arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else{
                while(st.size()>0 && st.top()<=arr[i]){
                    st.pop();
                }
                
                if(st.size() == 0){
                    ans[i]  = -1;
                }
                else{
                    ans[i] = st.top();
                }
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
