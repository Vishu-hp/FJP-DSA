// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
public:

    // RECURSION + MEMOIZATION
    // int solve(int arr[],int i,int j,vector<vector<int>>&memo){
    //     if(i==j){
    //         return 0;
    //     }
        
    //     if(memo[i][j] != -1){
    //         return memo[i][j];
    //     }
        
    //     int val=INT_MAX;
    //     for(int k=i;k<=j-1;k++){
    //         val = min(val, solve(arr,i,k,memo)+solve(arr,k+1,j,memo) + arr[i-1]*arr[k]*arr[j]);
    //     }
    //     return memo[i][j] = val;
    // }

    // int matrixMultiplication(int N, int arr[])
    // {
    //     // code here
    //     vector<vector<int>>memo(N,vector<int>(N,-1));
    //     return solve(arr,1,N-1,memo);
    // }
    
    
    // TABULATION
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>tab(N,vector<int>(N,INT_MAX));
        for(int i=1;i<N;i++){
            tab[i][i] = 0;
        }
        
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int val=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    val = min(val, tab[i][k]+tab[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
                tab[i][j] = val;
            }
        }
        return tab[1][N-1];
    }
};
