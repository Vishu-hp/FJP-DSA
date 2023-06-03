class Solution {
public:
    int largestAreaHistogram(vector<int>&heights){
        int n=heights.size();
        vector<int>rb(n);
        stack<int>st1;
        st1.push(n-1);
        rb[n-1] = n;
        
        for(int i=n-2;i>=0;i--){
            while(st1.size()>0 && heights[i]<=heights[st1.top()]){
                st1.pop();
            }
            
            if(st1.size() == 0){
                rb[i] = n;
            }
            else{
                rb[i] = st1.top();
            }
            st1.push(i);
        }
        
        vector<int>lb(n);
        stack<int>st2;
        st2.push(0);
        lb[0] = -1;
        
        for(int i=1;i<n;i++){
            while(st2.size()>0 && heights[i]<=heights[st2.top()]){
                st2.pop();
            }
            
            if(st2.size() == 0){
                lb[i] = -1;
            }
            else{
                lb[i] = st2.top();
            }
            st2.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int w = rb[i]-lb[i]-1;
            int a = w*heights[i];
            ans=max(ans,a);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         int n = matrix.size();
         int m = matrix[0].size();
         vector<int>h(m,0);
        for(int i=0;i<m;i++){
            if(matrix[0][i] == '0'){
                h[i] = 0;
            }
            else{
                h[i] = 1;
            }
        }
        
        int maxarea = largestAreaHistogram(h);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    h[j]++;
                }
                else{
                    h[j]=0;
                }
            }
            int ar = largestAreaHistogram(h);
            maxarea = max(maxarea, ar);
        }
        return maxarea;
    }
};
