class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(vector<vector<int>>&mat,int r,int c,vector<vector<int>>&dp){
    //     if(c<0 || c>=mat[0].size()){
    //         return INT_MAX;
    //     }  

    //     if(r==mat.size()-1){
    //         return mat[r][c];
    //     }

    //     if(dp[r][c] != -1){
    //         return dp[r][c];
    //     }

    //     int d = solve(mat,r+1,c,dp);
    //     int ld = solve(mat,r+1,c-1,dp);
    //     int rd = solve(mat,r+1,c+1,dp); 
 
    //     return dp[r][c] = mat[r][c] + min({d, ld, rd});
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
        
    //     int ans=INT_MAX;
    //     for(int i=0;i<n;i++){
    //         ans = min(ans, solve(matrix,0,i,dp));
    //     }
    //     return ans;
    // }

    // TABULATION
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>>tab(n,vector<int>(n,0));
    //     int ans=INT_MAX;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<n;j++){
    //             if(i==n-1){
    //                 tab[i][j] = matrix[i][j];
    //             }
    //             else{
    //                 int a = (i+1<n)?tab[i+1][j]:INT_MAX;
    //                 int b = (i+1<n && j-1>=0)?tab[i+1][j-1]:INT_MAX;
    //                 int c = (i+1<n && j+1<n)?tab[i+1][j+1]:INT_MAX;
                    
    //                 tab[i][j] = matrix[i][j] + min({a,b,c});
    //             }

    //              if(i==0){
    //                ans=min(ans, tab[i][j]);
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // SPACE OPTIMIZATION
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>next(n,0), curr(n,0);
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==n-1){
                    curr[j] = matrix[i][j];
                }
                else{
                    int a = next[j];
                    int b = (j-1>=0)?next[j-1]:INT_MAX;
                    int c = (j+1<n)?next[j+1]:INT_MAX;
                    
                    curr[j] = matrix[i][j] + min({a,b,c});
                }
            }
            next = curr;
        }

        for(int i=0;i<n;i++){
            ans = min(ans, next[i]);
        }

        return ans;
    }
};
