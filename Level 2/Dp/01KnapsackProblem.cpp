// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// RECURSION + MEMOIZATION
// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int solve(int wt[],int val[],int idx,int w,vector<vector<int>>&memo){
//         if(w==0 || idx<0){
//             return 0;
//         }
        
//         if(memo[idx][w] != -1){
//             return memo[idx][w];
//         }
        
        
        
//         int a1 = (wt[idx]<=w)?val[idx]+solve(wt,val,idx-1,w-wt[idx],memo):0;
//         int a2 = solve(wt,val,idx-1,w,memo);
        
//         return memo[idx][w] = max(a1,a2);
//     }
    
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//       // Your code here
//       vector<vector<int>>memo(n,vector<int>(W+1,-1));
//       return solve(wt,val,n-1,W,memo);
//     }
// };

//TABULATION
// class Solution
// {
//     public:
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//       // Your code here
//       vector<vector<int>>tab(n,vector<int>(W+1,-1));
       
//       for(int i=0;i<n;i++){
//           for(int j=0;j<W+1;j++){
//               if(j==0){
//                     tab[i][j] = 0;
//               }
//               else if(i==0){
//                   if(wt[i]<=j){
//                       tab[i][j] = val[i];
//                   }
//                   else{
//                       tab[i][j]=0;
//                   }
//               }
//               else{
//                   int a1 =(wt[i]<=j)?val[i] + tab[i-1][j-wt[i]]:0;
//                   int a2 = tab[i-1][j];
                   
//                   tab[i][j] = max(a1,a2);
//               }
//           }
//       }
//       return tab[n-1][W];
//     }
// };

// SPACE OPTIMIZATION
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int>prev(W+1,0), curr(W+1,0);
       
       for(int i=0;i<n;i++){
           for(int j=0;j<W+1;j++){
               if(j==0){
                    curr[j] = 0;
               }
               else if(i==0){
                   if(wt[i]<=j){
                       curr[j] = val[i];
                   }
                   else{
                       curr[j]=0;
                   }
               }
               else{
                   int a1 =(wt[i]<=j)?val[i] + prev[j-wt[i]]:0;
                   int a2 = prev[j];
                   
                   curr[j] = max(a1,a2);
               }
           }
           prev=curr;
       }
       return prev[W];
    }
};

