class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(vector<vector<int>>&grid,int r,int c,vector<vector<int>>&dp){
    //     if(r==0 && c==0){
    //         return grid[0][0];
    //     }

    //     if(r<0 || c<0){
    //         return INT_MAX;
    //     }

    //     if(dp[r][c] != -1){
    //         return dp[r][c];
    //     }

    //     return dp[r][c] =  grid[r][c]+ min(solve(grid,r,c-1,dp), solve(grid,r-1,c,dp)); 
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return solve(grid, m-1, n-1,dp);   
    // }

    // TABULATION
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>>dp(m,vector<int>(n,-1));

    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 && j==0){
    //                 dp[i][j] = grid[0][0];
    //             }
    //             else{
    //                 int a = (i>0)?dp[i-1][j]:INT_MAX;
    //                 int b = (j>0)?dp[i][j-1]:INT_MAX;

    //                 dp[i][j] = grid[i][j] + min(a,b);
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];

    // SPACE OPTIMIZATION
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>prev(n,INT_MAX);

        for(int i=0;i<m;i++){
            vector<int>curr(n,INT_MAX);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j] = grid[0][0];
                }
                else{
                    int a = (i>0)?prev[j]:INT_MAX;
                    int b = (j>0)?curr[j-1]:INT_MAX;

                    curr[j] = grid[i][j] + min(a,b);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
