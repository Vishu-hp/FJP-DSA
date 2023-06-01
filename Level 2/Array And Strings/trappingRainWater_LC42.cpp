// STACK

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(st.size()>0 && height[st.top()] <= height[i]){
                int rm = i;
                int curr = st.top();
                st.pop();
                if(st.size() == 0){
                    break;
                }
                int lm = st.top();
                int w = (rm-lm-1);
                ans += (min(height[rm],height[lm])-height[curr])*w;
            }
            st.push(i);
        }
        return ans;
    }
};

// O(1) SPACE
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int lpos = 1;
        int rpos = n-2;
        int water = 0;
        while(lpos <= rpos)
        {
            if(height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if(height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if(lmax <= rmax && height[lpos] < lmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        
        }
        return water;
    }
};
