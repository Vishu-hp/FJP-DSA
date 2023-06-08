class Solution {
public:
// RECURSION + MEMOIZATION
    // int solve(string s, string t, int m,int n, vector<vector<int>>&memo){
    //     if(n==0){
    //         return 1;
    //     }
    //     if(m==0){
    //         return 0;
    //     }

    //     if(memo[m][n] != -1){
    //         return memo[m][n];
    //     }

    //     if(s[m-1] == t[n-1]){
    //         return memo[m][n] = solve(s, t, m-1,n-1, memo) + solve(s, t, m-1,n, memo);
    //     }
    //     else{
    //         return memo[m][n] = solve(s, t, m-1, n , memo);
    //     }
    // }

    // int numDistinct(string s, string t) {
    //     int m=s.length();
    //     int n = t.length();
    //     vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
    //     return solve(s,t,m ,n, memo);
    // }

    // TABULATION
    // int numDistinct(string s, string t) {
    //     int m=s.length();
    //     int n = t.length();
    //     vector<vector<double>>tab(m+1,vector<double>(n+1,-1));
        
    //     for(int i=0;i<m+1;i++){
    //         for(int j=0;j<n+1;j++){
    //             if(j==0){
    //                 tab[i][j] = 1;
    //             }
    //             else if(i==0){
    //                 tab[i][j] = 0;
    //             }
    //             else{
    //                 if(s[i-1] == t[j-1]){
    //                     tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
    //                 }
    //                 else{
    //                     tab[i][j] = tab[i-1][j];
    //                 }
    //             }
    //         }
    //     }
    //     return (int)tab[m][n];
    // }

    // SPACE OPTIMIZATION
      int numDistinct(string s, string t) {
        int m=s.length();
        int n = t.length();
        vector<double>prev(n+1,-1), curr(n+1,-1);
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(j==0){
                    curr[j] = 1;
                }
                else if(i==0){
                    curr[j] = 0;
                }
                else{
                    if(s[i-1] == t[j-1]){
                        curr[j] = prev[j-1] + prev[j];
                    }
                    else{
                        curr[j] = prev[j];
                    }
                }
            }
            prev = curr;
        }
        return (int)prev[n];
    }
};
