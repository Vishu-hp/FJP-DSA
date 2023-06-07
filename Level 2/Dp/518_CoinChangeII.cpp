class Solution {
public:
// RECURSION + MEMOIZATION
    // int solve(vector<int>&coins,int idx,int amt,vector<vector<int>>&memo){
    //     if(amt == 0){
    //         return 1;
    //     }

    //     if(idx<0){
    //         return 0;
    //     }

    //     if(memo[idx][amt] != -1){
    //         return memo[idx][amt];
    //     }

    //     int a1 = (coins[idx]<=amt)?solve(coins,idx,amt-coins[idx],memo):0;
    //     int a2 = solve(coins,idx-1,amt,memo);

    //     return memo[idx][amt]=a1+a2;
    // }

    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>>memo(n,vector<int>(amount+1,-1));
    //     return solve(coins,n-1,amount,memo);
    // }

    // TABULATION
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>>tab(n,vector<int>(amount+1,-1));
        
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<amount+1;j++){
    //             if(j==0){
    //                 tab[i][j] = 1;
    //             }
    //             else if(i==0){
    //                 if(j%coins[i] == 0){
    //                     tab[i][j]=1;
    //                 }
    //                 else{
    //                     tab[i][j] = 0;
    //                 }
    //             }
    //             else{
    //                 int a1 = (coins[i]<=j)?tab[i][j-coins[i]]:0;
    //                 int a2 = tab[i-1][j];

    //                 tab[i][j] = a1+a2;
    //             }
    //         }
    //     }
    //     return tab[n-1][amount];
    // }

    // SPACE OPTIMIZATION
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0), curr(amount+1,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<amount+1;j++){
                if(j==0){
                    curr[j] = 1;
                }
                else if(i==0){
                    if(j%coins[i] == 0){
                        curr[j]=1;
                    }
                    else{
                        curr[j] = 0;
                    }
                }
                else{
                    int a1 = (coins[i]<=j)?curr[j-coins[i]]:0;
                    int a2 = prev[j];

                    curr[j] = a1+a2;
                }
            }

            prev=curr;
        }
        return prev[amount];
    }
};
