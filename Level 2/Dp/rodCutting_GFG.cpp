// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
  public:
//   RECURSION + MEMOIZATION
    // int solve(int price[], int n,vector<int>&memo){
    //     if(n==0){
    //         return 0;
    //     }
        
    //     if(memo[n] != -1){
    //         return memo[n];
    //     }
        
    //     int ans=INT_MIN;
    //     for(int i=1;i<=n;i++){
    //         int tmpAns = (n>=i)?solve(price,n-i,memo) + price[i-1]:0;
    //         ans = max(ans, tmpAns);
    //     }
    //     return memo[n] = ans;
    // }
  
    // int cutRod(int price[], int n) {
    //     //code here
    //     vector<int>memo(n+1,-1);
    //     return solve(price, n, memo);
    // }
    
    // TABULATION
    int cutRod(int price[], int n) {
        //code here
        vector<int>tab(n+1,-1);
        
        for(int i=0;i<n+1;i++){
            if(i==0){
                tab[i]=0;
            }
            else{
                int ans=INT_MIN;
                for(int j=1;j<=i;j++){
                    ans = max(ans, tab[i-j] + price[j-1]);
                }
                
                tab[i] = ans;
            }
        }
        
        return tab[n];
    }
};
