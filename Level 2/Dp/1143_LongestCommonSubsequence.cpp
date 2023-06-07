class Solution {
public:
// RECURSION + MEMOIZATION
    // int solve(string s1,string s2,int m,int n,vector<vector<int>>&memo){
    //     if(m==0 || n==0){
    //         return 0;
    //     }

    //     if(memo[m][n] != -1){
    //         return memo[m][n];
    //     }

    //     if(s1[m-1] == s2[n-1]){
    //         return memo[m][n] = 1 + solve(s1,s2,m-1,n-1,memo);
    //     }
    //     else{
    //         return memo[m][n] = max(solve(s1,s2,m-1,n,memo), solve(s1,s2,m,n-1,memo));
    //     }
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size();
    //     int n = text2.size();

    //     vector<vector<int>>memo(m+1,vector<int>(n+1,-1));    
    //     return solve(text1,text2,m,n,memo);
    // }

    // TABULATION
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size();
    //     int n = text2.size();

    //     vector<vector<int>>tab(m+1,vector<int>(n+1,-1));    
        
    //     for(int i=0;i<m+1;i++){
    //         for(int j=0;j<n+1;j++){
    //             if(i==0 || j==0){
    //                 tab[i][j] = 0;
    //             }
    //             else{
    //                 if(text1[i-1] == text2[j-1]){
    //                     tab[i][j] = 1+tab[i-1][j-1];
    //                 }
    //                 else{
    //                     tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
    //                 }
    //             }
    //         }
    //     }

    //     return tab[m][n];
    // }

    // SPACE OPTIMIZATION
     int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int>prev(n+1,0), curr(n+1,0);    
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    curr[j] = 0;
                }
                else{
                    if(text1[i-1] == text2[j-1]){
                        curr[j] = 1+ prev[j-1];
                    }
                    else{
                        curr[j] = max(prev[j], curr[j-1]);
                    }
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
