class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans=0;
        int i=0, j=n-1;
        while(i<j){
            int h1 = height[i];
            int h2 = height[j];
            int w = (j-i)*min(h1, h2);
            if(ans < w){
                ans=w;
            }

            if(h1<h2){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
