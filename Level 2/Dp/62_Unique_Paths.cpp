class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(int m,int n,vector<vector<int>>&memo){
    //     if(m==1 && n==1){
    //         return 1;
    //     }

    //     if(m<1 || n<1){
    //         return 0;
    //     }

    //     if(memo[m][n] != -1){
    //         return memo[m][n];
    //     }

    //     return memo[m][n] = solve(m-1, n, memo) + solve(m,n-1,memo);
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>memo(m+1, vector<int>(n+1,-1));
    //     return solve(m,n,memo);
    // }

    // TABULATION
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>tab(m+1, vector<int>(n+1,-1));

    //     for(int i=1;i<m+1;i++){
    //         for(int j=1;j<n+1;j++){
    //             if(i==1 || j==1){
    //                 tab[i][j] = 1;
    //             }
    //             else{
    //                 int a = (i>1)?tab[i-1][j]:0;
    //                 int b = (j>1)?tab[i][j-1]:0;
    //                 tab[i][j] = a+b;
    //             }
    //         }
    //     }

    //     return tab[m][n];
    // }

    // SPACE OPTIMIZATION
    int uniquePaths(int m, int n) {
        vector<int>prev(n+1, 0);

        for(int i=1;i<m+1;i++){
            vector<int>curr(n+1,0);
            for(int j=1;j<n+1;j++){
                if(i==1 || j==1){
                    curr[j] = 1;
                }
                else{
                    int a = (i>1)?prev[j]:0;
                    int b = (j>1)?curr[j-1]:0;
                    curr[j] = a+b;
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};
