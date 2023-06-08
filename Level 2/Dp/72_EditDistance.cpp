class Solution {
public:
    // RECURSION + MEMOIZATION
    // int solve(string s1, string s2,int m,int n,vector<vector<int>>&memo){
    //     if(m==0){
    //         return n;
    //     }

    //     if(n==0){
    //         return m;
    //     }

    //     if(memo[m][n] != -1){
    //         return memo[m][n];
    //     }


    //     if(s1[m-1] == s2[n-1]){
    //         return memo[m][n] = solve(s1,s2,m-1,n-1,memo);
    //     }
    //     else{
    //         int a1 = solve(s1, s2, m, n-1,memo);
    //         int a2 = solve(s1, s2, m-1, n,memo);
    //         int a3 = solve(s1, s2, m-1, n-1,memo);

    //         return memo[m][n] = 1+ min({a1,a2,a3});
    //     }
    // }

    // int minDistance(string word1, string word2) {
    //     int m = word1.size();
    //     int n = word2.size();
    //     vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
    //     return solve(word1, word2, m, n, memo);
    // }

    // TABULATION
    // int minDistance(string word1, string word2) {
    //     int m = word1.size();
    //     int n = word2.size();
    //     vector<vector<int>>tab(m+1,vector<int>(n+1,-1));
        
    //     for(int i=0;i<m+1;i++){
    //         for(int j=0;j<n+1;j++){
    //             if(i==0){
    //                 tab[i][j] = j;
    //             }
    //             else if(j==0){
    //                 tab[i][j] = i;
    //             }
    //             else{
    //                 if(word1[i-1] == word2[j-1]){
    //                     tab[i][j] = tab[i-1][j-1];
    //                 }
    //                 else{
    //                     int a1 = tab[i][j-1];
    //                     int a2 = tab[i-1][j];
    //                     int a3 = tab[i-1][j-1];

    //                     tab[i][j] = 1+min({a1,a2,a3});
    //                 }
    //             }
    //         }
    //     }

    //     return tab[m][n];
    // }

    // SPACE OPTIMIZATION
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int>prev(n+1,-1), curr(n+1, -1);
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0){
                    curr[j] = j;
                }
                else if(j==0){
                    curr[j] = i;
                }
                else{
                    if(word1[i-1] == word2[j-1]){
                        curr[j] = prev[j-1];
                    }
                    else{
                        int a1 = curr[j-1];
                        int a2 = prev[j];
                        int a3 = prev[j-1];

                        curr[j] = 1+min({a1,a2,a3});
                    }
                }
            }
            prev = curr;
        }

        return curr[n];
    }
};
