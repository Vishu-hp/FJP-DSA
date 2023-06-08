class Solution {
public:
    // RECURSION + MEMOIZATION
    // bool solve(string s,string p,int m,int n, vector<vector<int>>&memo){
    //     if(m==0 && n==0){
    //         return true;
    //     }

    //     if(n==0 && m!=0){
    //         return false;
    //     }

    //     if(m==0 && n>=0){
    //         for(int i=0;i<n;i++){
    //             if(p[i]!='*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     if(memo[m][n] != -1){
    //         return memo[m][n];
    //     }

    //     if(p[n-1]=='?' || s[m-1]==p[n-1]){
    //         return memo[m][n] = solve(s,p,m-1,n-1,memo);
    //     }
    //     else if(p[n-1]=='*'){
    //         bool a1 = solve(s,p,m-1,n,memo);
    //         bool a2 = solve(s,p,m,n-1,memo);

    //         return memo[m][n] = a1||a2;
    //     }
    //     else{
    //         return memo[m][n] = false;
    //     }
    // }

    // bool isMatch(string s, string p) {
    //    int m = s.length(); 
    //    int n = p.length(); 

    //    vector<vector<int>>memo(m+1,vector<int>(n+1,-1)); 
    //    return solve(s,p,m,n,memo);
    // }

    // TABULATION
    // bool isMatch(string s, string p) {
    //    int m = s.length(); 
    //    int n = p.length(); 

    //    vector<vector<int>>tab(m+1,vector<int>(n+1,-1)); 

    //     for(int i=0;i<m+1;i++){
    //         for(int j=0;j<n+1;j++){
    //             if(i==0 && j==0){
    //                 tab[i][j] = true;
    //             }
    //             else if(j==0 && i!=0){
    //                 tab[i][j] = false;
    //             }
    //             else if(i==0 && j>=0){
    //                 tab[i][j]=true;
    //                 for(int k=1;k<=j;k++){
    //                     if(p[k-1]!='*'){
    //                         tab[i][j]=false;
    //                         break;
    //                     }
    //                 }
    //             }
    //             else{
    //                 if(p[j-1]=='?' || s[i-1]==p[j-1]){
    //                     tab[i][j] = tab[i-1][j-1];
    //                 }
    //                 else if(p[j-1]=='*'){
    //                     bool a1 = tab[i-1][j];
    //                     bool a2 = tab[i][j-1];

    //                     tab[i][j] = a1||a2;
    //                 }
    //                 else{
    //                     tab[i][j] = false;
    //                 }   
    //             }
    //         }
    //     }
    //     return tab[m][n];
    // }

    // SPACE OPTIMIZATION
     bool isMatch(string s, string p) {
       int m = s.length(); 
       int n = p.length(); 

       vector<int>prev(n+1,-1), curr(n+1,-1); 

        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 && j==0){
                    curr[j] = true;
                }
                else if(j==0 && i!=0){
                    curr[j] = false;
                }
                else if(i==0 && j>=0){
                    curr[j]=true;
                    for(int k=1;k<=j;k++){
                        if(p[k-1]!='*'){
                            curr[j]=false;
                            break;
                        }
                    }
                }
                else{
                    if(p[j-1]=='?' || s[i-1]==p[j-1]){
                        curr[j] = prev[j-1];
                    }
                    else if(p[j-1]=='*'){
                        bool a1 = prev[j];
                        bool a2 = curr[j-1];

                        curr[j] = a1||a2;
                    }
                    else{
                        curr[j] = false;
                    }   
                }
            }
            prev= curr;
        }
        return prev[n];
    }
};
